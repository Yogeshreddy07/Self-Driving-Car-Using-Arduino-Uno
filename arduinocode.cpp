//This code is written specifically for Arduino Uno, but the syntax and logic closely resemble C++
// Motor A connections
int enA = 9;
int in1 = 2;
int in2 = 3;
char command = '0';  // Initialize command variable

// Motor B connections
int enB = 10;
int in3 = 4;
int in4 = 5;

// Movement states
enum Movement {FORWARD, BACKWARD, LEFT, RIGHT, STOP};
Movement moveState;

void setup() {
  // Set all the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initialize Serial communication for Bluetooth module
  Serial.begin(9600); // Set baud rate to match the Bluetooth module

  // Start with motors off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Set initial movement state
  moveState = STOP;
}

void loop() {
  // Check if there is any data coming from the Bluetooth module
  if (Serial.available() > 0) {
    command = Serial.read();  // Read the incoming command
   
    // Debugging: Print received command
    Serial.print("Received command: ");
    Serial.println(command);

    // Determine the movement based on the received command
    switch(command) {
      case 'f':
        moveState = FORWARD;
        break;
      case 'b':
        moveState = BACKWARD;
        break;
      case 'l':
        moveState = LEFT;
        break;
      case 'r':
        moveState = RIGHT;
        break;
      case 's':
        moveState = STOP;
        break;
      default:
        moveState = STOP;
        break;
    }
  }

  // Execute the movement based on the current state
  switch(moveState) {
    case FORWARD:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 255);  // Full speed Motor A
      analogWrite(enB, 255);  // Full speed Motor B
      delay(50);  // Duration of 3 seconds
      moveState = STOP;  // Reset state to stop after moving
      break;

    case BACKWARD:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 255);  // Full speed Motor A
      analogWrite(enB, 255);  // Full speed Motor B
      delay(50);  // Duration of 3 seconds
      moveState = STOP;  // Reset state to stop after moving
      break;

    case LEFT:
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW); // Stop Motor A
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW); // Motor B moves forward
      analogWrite(enA, 0);    // Stop Motor A
      analogWrite(enB, 255);  // Full speed Motor B
      delay(50);  // Duration of 2 seconds
      moveState = STOP;  // Reset state to stop after turning
      break;

    case RIGHT:
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW); // Motor A moves forward
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW); // Stop Motor B
      analogWrite(enA, 255);  // Full speed Motor A
      analogWrite(enB, 0);    // Stop Motor B
      delay(50);  // Duration of 2 seconds
      moveState = STOP;  // Reset state to stop after turning
      break;

    case STOP:
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      break;
  }
  delay(100); // Small delay to stabilize output
}
