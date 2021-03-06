void drive_straight(int left45_sensor, int left90_sensor, int right45_sensor, int right90_sensor) // 2 or 4 sensors?
{
                                           // analog read values of 2 or 4 sensors passed to function
  static int previous_error = 0;
  static int Kp = 16, Ki = 1, Kd = 4;      // constants for scaling P I D effects (will need adjusting)
  static int error, P, I = 0,  D;      // error variables
  int total; 
  
  error = (right45_sensor + right90_sensor)/2 - (left_45sensor + left90_sensor)/2;
  
  P = error * Kp;
  
  I = (I + error)*Ki;    
  
  D = (error - previous_error) * Kd;       // may take out
  previous_error = error;
  
  total = (P+I+D);

  {
    L_enable_val -= (total);
      L_enable_val = constrain(L_enable_val, 30000, 65535);      // may need to adjust
    
    R_enable_val += (total); 
      R_enable_val = constrain(R_enable_val, 30000, 65535);
    
    pwmWrite(left_enable, L_enable_val);            // enable pins and values 
                                                     // must be global
    pwmWrite(right_enable, R_enable_val);          // arduino uses analogWrite
  }
}
