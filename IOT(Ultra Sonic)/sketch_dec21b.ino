// defines pins numbers
int trigPin = 9;      // Pin connected to the trigger of the ultrasonic sensor
int echoPin = 10;     // Pin connected to the echo of the ultrasonic sensor
int buzz = 8;         // Pin connected to a buzzer indicating a specific distance level
int led1 = 13;        // Pin connected to an LED indicating a distance level
int led2 = 12;        // Pin connected to an LED indicating another distance level
int led3 = 11;        // Pin connected to an LED indicating another distance level

// defines variables
long duration;         // Variable to store the duration of the ultrasonic pulse travel
int distance;          // Variable to store the calculated distance in centimeters

void setup() {
  pinMode(trigPin, OUTPUT);  // Configures trigPin (9) as an OUTPUT pin
  pinMode(echoPin, INPUT);   // Configures echoPin (10) as an INPUT pin
  pinMode(buzz, OUTPUT);     // Configures buzzer pin as an OUTPUT pin
  pinMode(led1, OUTPUT);     // Configures LED pins as OUTPUT pins
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);        // Initializes serial communication at 9600 baud rate
}

void loop() {
  digitalWrite(trigPin, LOW);            // Clears the trigPin
  delayMicroseconds(2);                  // Waits for 2 microseconds
  
  digitalWrite(trigPin, HIGH);           // Triggers the ultrasonic sensor
  delayMicroseconds(10);                 // Keeps the trigger on for 10 microseconds
  digitalWrite(trigPin, LOW);            // Turns off the trigger
  
  duration = pulseIn(echoPin, HIGH);     // Measures the duration of the echo
  distance = duration * 0.034 / 2;       // Calculates distance based on the duration

  if (distance <= 5) {
    // Red LED on, others off
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    // Emit fastest sensor car sound for closest distance
    for (int i = 0; i < 3; ++i) {
      digitalWrite(buzz, HIGH);
      delay(50);
      digitalWrite(buzz, LOW);
      delay(50);
    }
  } else if (distance > 5 && distance <= 10) {
    // Yellow LED on, others off
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    // Emit faster sensor car sound for closer distance
    for (int i = 0; i < 3; ++i) {
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
    }
  } else if (distance > 10 && distance <= 15) {
    // Green LED on, others off
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    // Emit sensor car sound for closer distance
    for (int i = 0; i < 3; ++i) {
      digitalWrite(buzz, HIGH);
      delay(200);
      digitalWrite(buzz, LOW);
      delay(200);
    }
  } else {
    // All LEDs off if beyond specified distances
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(buzz, LOW);
  }

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
