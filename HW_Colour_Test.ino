/*
  Hockey Warrior - Colour Test
  Tests the Green mat & Ball colour sensors & prints the results
 */
 
 #include "config.h"

int GML_Off;
int GML_RED_On;
int GML_GREEN_On;
int GML_RED_Diff;
int GML_GREEN_Diff;

int GMR_Off;
int GMR_RED_On;
int GMR_GREEN_On;
int GMR_RED_Diff;
int GMR_GREEN_Diff;

int BALL_Off;
int BALL_RED_On;
int BALL_IR_On;
int BALL_RED_Diff;
int BALL_IR_Diff;

void setup() {
	// Set IR pins as outputs
  pinMode(GREEN_MAT_LEFT_RED_LED_PIN, OUTPUT);
  pinMode(GREEN_MAT_LEFT_GREEN_LED_PIN, OUTPUT);
  pinMode(GREEN_MAT_RIGHT_RED_LED_PIN, OUTPUT);
  pinMode(GREEN_MAT_RIGHT_GREEN_LED_PIN, OUTPUT);
  pinMode(BALL_COLOUR_RED_LED_PIN, OUTPUT);
  pinMode(BALL_COLOUR_IR_LED_PIN, OUTPUT);
  
  Serial.begin(115200);      // open the serial port at 9600 bps:

  DEBUG_PRINT("Starting...");
}

void loop() {
	// Read each sensor in a loop
  digitalWrite(GREEN_MAT_LEFT_RED_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  GML_RED_On = analogRead(GREEN_MAT_LEFT_PHOTOTRANSISTOR_PIN);
  digitalWrite(GREEN_MAT_LEFT_RED_LED_PIN, LOW);

  digitalWrite(GREEN_MAT_LEFT_GREEN_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  GML_GREEN_On = analogRead(GREEN_MAT_LEFT_PHOTOTRANSISTOR_PIN);
  digitalWrite(GREEN_MAT_LEFT_GREEN_LED_PIN, LOW);

  digitalWrite(GREEN_MAT_RIGHT_RED_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  GMR_RED_On = analogRead(GREEN_MAT_RIGHT_PHOTOTRANSISTOR_PIN);
  digitalWrite(GREEN_MAT_RIGHT_RED_LED_PIN, LOW);

  digitalWrite(GREEN_MAT_RIGHT_GREEN_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  GMR_GREEN_On = analogRead(GREEN_MAT_RIGHT_PHOTOTRANSISTOR_PIN);
  digitalWrite(GREEN_MAT_RIGHT_GREEN_LED_PIN, LOW);

  digitalWrite(BALL_COLOUR_RED_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  BALL_RED_On = analogRead(BALL_COLOUR_PHOTOTRANSISTOR_PIN);
  digitalWrite(BALL_COLOUR_RED_LED_PIN, LOW);

  digitalWrite(BALL_COLOUR_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  BALL_IR_On = analogRead(BALL_COLOUR_PHOTOTRANSISTOR_PIN);
  digitalWrite(BALL_COLOUR_IR_LED_PIN, LOW);
    
  delay(LED_READ_DELAY_TIME);
  GML_Off = analogRead(GREEN_MAT_LEFT_PHOTOTRANSISTOR_PIN);
  GMR_Off = analogRead(GREEN_MAT_RIGHT_PHOTOTRANSISTOR_PIN);
  BALL_Off = analogRead(BALL_COLOUR_PHOTOTRANSISTOR_PIN);
    
  GML_RED_Diff = GML_RED_On - GML_Off;
  GML_GREEN_Diff = GML_GREEN_On - GML_Off;
  GMR_RED_Diff = GMR_RED_On - GMR_Off;
  GMR_GREEN_Diff = GMR_GREEN_On - GMR_Off;
  BALL_RED_Diff = BALL_RED_On - BALL_Off;
  BALL_IR_Diff = BALL_IR_On - BALL_Off;
  
  PLOT("GML_Off", GML_Off);
  PLOT("GML_RED_On", GML_RED_On);
  PLOT("GML_GREEN_On", GML_GREEN_On);
  PLOT("GML_RED_Diff", GML_RED_Diff);
  PLOT("GML_GREEN_Diff", GML_GREEN_Diff);

  PLOT("GMR_Off", GMR_Off);
  PLOT("GMR_RED_On", GMR_RED_On);
  PLOT("GMR_GREEN_On", GMR_GREEN_On);
  PLOT("GMR_RED_Diff", GMR_RED_Diff);
  PLOT("GMR_GREEN_Diff", GMR_GREEN_Diff);

  PLOT("BALL_Off", BALL_Off);
  PLOT("BALL_RED_On", BALL_RED_On);
  PLOT("BALL_IR_On", BALL_IR_On);
  PLOT("BALL_RED_Diff", BALL_RED_Diff);
  PLOT("BALL_IR_Diff", BALL_IR_Diff);
}
