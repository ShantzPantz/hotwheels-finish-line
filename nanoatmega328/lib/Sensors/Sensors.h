class Sensors
{
private:
    int *_pins;
    int *_values;

public:
    Sensors(int pins[4]);
    ~Sensors();

    void update();
    int *get_values();

    static const int SENSOR_THRESH = 500;
};

