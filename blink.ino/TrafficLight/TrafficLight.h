#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

class TrafficLight {
    private:
      bool red;
      bool yellow;
      bool green;
      int* delay;  // 🔥 Now delay is dynamically allocated
      int state;
      enum STATE {
        RED,  // 0
        YELLOW_GREEN, // 1
        GREEN,  // 2
        YELLOW, // 3
        FLASHING_GREEN, // 4
      };
    public:
      TrafficLight();
      ~TrafficLight();
      void transition();
      int nextState();
      int getDelay();
      bool getRed();
      bool getYellow();
      bool getGreen();
      int getState();
      void printState();
      bool isFlashingG();

  };

#endif 