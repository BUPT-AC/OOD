/**
 * class:ElevatorController
 * - elevator
 * - queue of pending requests
 * - queue of emergence requests
 * + serviceNextRequest()
 * + addRequest()
 * + stopSystem()
 * + groundElevator()
 * 
 * class: Elevator
 * - array of buttons
 * - current request
 * - current floor
 * + getCurrentRequest()
 * + moveUp()
 * + moveDown()
 * + openDoor()
 * + closeDoor()
 * + beep()
 * 
 * class: abstract Request
 * - requesteType
 * + abstract setDirection()
 * 
 * class: FloorRequest
 * - floorNum
 * - direction(up/down)
 * + setDirection()
 * 
 * class: ElevatorRequest
 * - srcFloor
 * - direction(open door/ close door/ up/ down/ emergence call)
 * + serDirection()
 * + setSrcFloor()
 * + emmergenceCall()
 *
 *abstract class: button
 * - indicator
 * - illuminate()
 * - unIlluminate
 * - abstract placeRequest()
 * - abstract cancelRequest()
 * 
 * class: floorButton(subclass of button class)
 * - placeRequest(direction, floorNum);
 * - canCelRequest()
 * 
 * class: elevatorButton(subclass of button class)
 * + placeRequest(direction)
 * + setSrcFloorNum()
 * 
 * class: <<enumeration>> Direction
 * UP, DOWN, CLOSE, OPEN, EMERGENCE, MOVETOSRC
 */
