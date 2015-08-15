public enum Rank {
DIRECTOR, MANAGER, RESPONDENT;
}

abstract class Employee {
    public String name;
    public Rank rank;
    private Call curCall;
    
    public Employee(){}
    
    public void reveiveCall(Call call){}
    public void callComplete(){}
    public boolean isFree(){}
    public Rank getRank(){}
}

public class Director extends Emplyee{
    public Director() {
        this.Rank = Rank.DIRECTOR;
    }
}

public class Manager extends Employee{
    public Manager(){
        this.Rank = Rank.MANAGER;
    }
}

public class Respondent extends Employee {
    public Respondent(){
        this.Rank = Rank.RESPONDENT;
    }
}

public class Call {
    /* Minimal rank of employee who can handle this call */
    private Rank rank;
    
    private Caller caller;
    private Employee  handler;
    
    public Call(Caller c) {
        rank = Rank.RESPONDENT;
        caller = c;
    }
    
    public void setHandler(Employee e) {
        handler = e;
    }
    
    public void reply(){}
    public Rank getRank(){}
    public void setRank(){}
}

public class CallHandler {
    private static CallHandler instance;
    private final int LEVELS = 3;
    private int NUM_RESPONDENTS = 10;
    private int NUM_MANAGERS = 4;
    private int NUM_DIRECTORS = 2;
    //List of employees, by level.
    List<List<Employee>> employeeLevels;
    Queue<Call> calls;
    
    //Get instance of singleton class
    public static CallHandler getInstance() {
        if (instance == null) instance = new CallHandler();
        return instance;
    }
    //set a call to a free handler or add to a queue
    public void routeCall(Call c) {
        Employee emp = getFreeHandler();
        if (emp == null) {
            calls.offer(c);
            c.reply();
        } else {
            emp.reveiveCall(c);
            c.setHandler(emp);
        }
    }
    public Employee getFreeHandler() {
        
    }
    public boolean assignCall(Employee emp, Call c) {}
}
