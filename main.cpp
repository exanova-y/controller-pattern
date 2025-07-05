#include <iostream>
#include <string>

class BaseComponent; // declared before Controller.

class IController{
    // takes a pointer to the base component, and event.
    public: 
    virtual void Notify(BaseComponent* sender, std::string event) const = 0;// event is a string. it is an interface
    // virtual: to be overriden by subclasses. a virutal fn can't be instantiated.
    // void: no return value
    // = 0: this function must be overriden.
    // event is a string. std is the namespace (like a Python module), and :: is the scope resolution similar to . in Python.
};

class BaseComponent{ 
    // references the controller.
    protected: // protected: can be accessed by itself and children.
    IController* _controller;
    
    public:
    BaseComponent(IController* controller = nullptr) // name equals the classname. this is the init method.
        : _controller(controller){}
    
    void set_controller(IController* controller){
        _controller = controller;
    }
};


class ArmenianComponent: public BaseComponent{
    public:
    void RecruitArmenians(){ // погнали!! Let's go!
        std::cout << "Armenian is recruiting Armenians successfully!";
        _controller->Notify(this, "recruiting Armenians");
    }

    void HostReunion(){
        std::cout << "Armenian is hosting a slavic reunion successfully!";
        _controller->Notify(this, "hosting a slavic reunion");
    }
};