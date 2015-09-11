from page_crawler import page_crawler
from threading import BoundedSemaphore, Thread

class task:
	"""docstring for task"""
	def __init__(self, url):
		self.url = url
		self.state = "new"
		self.type = "page"

class TaskQueue:
	"""docstring for Ta"""
	numOfNewTasks = 0
	def __init__(self, event):
		self.numOfNewTasks = 0
		self.queue = []
		self.event = event

	def add(self, task):
		self.queue.append(task)
		self.numOfNewTasks += 1
		if self.event:
			self.event.set()
		# self.event.clear()

	def get(self):
		if self.numOfNewTasks > 0:	
			task = self.queue[0]
			self.queue.pop(0)
			self.numOfNewTasks -= 1
			return task
		else:
			if self.event:
				self.event.clear()
			return None
		
		


class Crawler(Thread):
	"""docstring for Crawler"""
	def __init__(self, taskQueue, TaskLock, PageQueue, PageLock, event, output):
		# super(Thread,self).__init__(self)
		Thread.__init__(self)
		self.TaskQueue = taskQueue
		self.TaskLock = TaskLock
		self.PageQueue = PageQueue
		self.PageLock = PageLock
		self.event = event

		self.crawler = page_crawler()
		self.doneTask = TaskQueue(None)
		self.donePage = TaskQueue(None)
		self.output = output

	def run(self):
		while True:
			self.event.wait()
			with self.TaskLock:
				task = self.TaskQueue.get()
				task.state = "working"
			page = self.crawler.getPage(task.url)
			if task.type == "list":
				with self.TaskLock:
					for newTask in page:
						self.TaskQueue.add(newTask)
					task.state = "done"
					self.doneTask.add(task)
			else:
				with self.PageLock:
					self.PageQueue.add(page)
					self.output.write(page)
				with self.TaskLock:
					task.state = "done"
					self.doneTask.add(task)
			if self.TaskQueue.numOfNewTasks == 0:
				return



		