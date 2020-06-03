void Setup()
{
  // put your setup code here, to run once:
          pinMode(SENSOR_S0, OUTPUT);
          pinMode(SENSOR_S1, OUTPUT);
          pinMode(SENSOR_S2, OUTPUT);
          pinMode(SENSOR_S3, OUTPUT);
          pinMode(SENSOR_OUT, INPUT);
   // Setting frequency-scaling to 20%
          digitalWrite(SENSOR_S0, HIGH);
          digitalWrite(SENSOR_S1, LOW);
                              pinMode(linksV, OUTPUT);
                              pinMode(linksR, OUTPUT);
                              pinMode(rechtsV, OUTPUT);
                              pinMode(rechtsR, OUTPUT);
                              
  pinMode(A0, INPUT);           //sensoren als input definieren
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

   pixels.begin();
  
  Serial.begin(115200);
  Serial.print("Starting...\n");
 
  // initialize the pixy object 
              pixy.init();
              // using the color connected components program
              pixy.changeProg("color_connected_components");
              pixy.setLamp(1, 1);         //activate the led´s
             delay(10);
              setPixelBlue();
}
