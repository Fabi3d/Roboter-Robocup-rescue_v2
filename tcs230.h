#define SENSOR_S0 9
#define SENSOR_S1 8
#define SENSOR_S2 11
#define SENSOR_S3 10
#define SENSOR_OUT 12

int frequency = 0;
long f1 = 0;
long f2 = 0;
long f3 = 0;

void tcs()
{
  // Setting RED filtered photodiodes to be read
  digitalWrite(SENSOR_S2, LOW);
  digitalWrite(SENSOR_S3, LOW);
  f1 = pulseIn(SENSOR_OUT, LOW); // Reading the output frequency

  // Printing RED value on the serial monitor
 /* Serial.print("R=");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);
*/
  // Setting GREEN filtered photodiodes to be read
  digitalWrite(SENSOR_S2, HIGH);
  digitalWrite(SENSOR_S3, HIGH);
  f2 = pulseIn(SENSOR_OUT, LOW);


  // Printing GREEN value on the serial monitor
 /* Serial.print("G=");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);
*/
  // Setting BLUE filtered photodiodes to be read
  digitalWrite(SENSOR_S2, LOW);
  digitalWrite(SENSOR_S3, HIGH);
  f3 = pulseIn(SENSOR_OUT, LOW);
Serial.print(f1);
Serial.print("   ");
Serial.print(f2);
Serial.print("   ");
Serial.print(f3);
Serial.print("     ");
Serial.println(f1+f2+f3);



  /*// Printing BLUE value on the serial monitor
  Serial.print("B=");
  Serial.print(frequency);
  Serial.println("  ");
  delay(100);*/
}
