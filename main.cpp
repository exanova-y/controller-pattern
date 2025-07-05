

class BaseComponent; // declared before Controller.

class IController{
    // sender, and event.
    public: 
    virtual void Notify(BaseComponent*sender, std::string event) const = 0;// event is a string. it is an interface
}

class BaseComponent{ 
    // references the controller.
    protected;
    IController* controller;
    public:
    BaseComponent(IController* controller = nullptr): _controller(controller){}
}