#include <iostream>
#include <string>

using namespace std;

class EngineInterface
{
};
class SportEngine : public EngineInterface
{
};
class SUVEngine : public EngineInterface
{
};

class BuilderInterface
{
public:
    virtual void reset() = 0;
    virtual void setSeats(int count) = 0;
    virtual void setEngines(EngineInterface *engine) = 0;
    virtual void setTripComputer() = 0;
    virtual void setGPS() = 0;
};

class CarBuilder : public BuilderInterface
{
private:
    EngineInterface *engine;
    int seats;
    bool tripComputer;
    bool gps;

public:
    void reset()
    {
        engine = nullptr;
        seats = 0;
        tripComputer = false;
        gps = false;
        cout << "CarBuilder reset" << endl;
    }
    void setSeats(int count)
    {
        seats = count;
        cout << "CarBuilder setSeats" << endl;
    }
    void setEngines(EngineInterface *engine)
    {
        this->engine = engine;
        cout << "CarBuilder setEngines" << endl;
    }
    void setTripComputer()
    {
        tripComputer = true;
        cout << "CarBuilder setTripComputer" << endl;
    }
    void setGPS()
    {
        gps = true;
        cout << "CarBuilder setGPS" << endl;
    }
};

class ManualBuilder : public BuilderInterface
{
private:
    EngineInterface *engine;
    int seats;
    bool tripComputer;
    bool gps;

public:
    void reset()
    {
        engine = nullptr;
        seats = 0;
        tripComputer = false;
        gps = false;
        cout << "ManualBuilder reset" << endl;
    }
    void setSeats(int count)
    {
        seats = count;
        cout << "ManualBuilder setSeats" << endl;
    }
    void setEngines(EngineInterface *engine)
    {
        this->engine = engine;
        cout << "ManualBuilder setEngines" << endl;
    }
    void setTripComputer()
    {
        tripComputer = true;
        cout << "ManualBuilder setTripComputer" << endl;
    }
    void setGPS()
    {
        gps = true;
        cout << "ManualBuilder setGPS" << endl;
    }
};

class Director
{
public:
    void makeSUV(BuilderInterface *builder)
    {
        builder->reset();
        builder->setSeats(114);
        builder->setEngines(new SUVEngine());
        builder->setTripComputer();
        builder->setGPS();
    }

    void makeSportsCar(BuilderInterface *builder)
    {
        builder->reset();
        builder->setSeats(514);
        builder->setEngines(new SportEngine());
        builder->setTripComputer();
    }
};

int main()
{
    Director director;
    CarBuilder carBuilder;
    ManualBuilder manualBuilder;

    director.makeSUV(&carBuilder);
    director.makeSportsCar(&manualBuilder);

    return 0;
}