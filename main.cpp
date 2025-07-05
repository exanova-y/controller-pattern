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
    // mediator component. the controller.
    protected: // protected: can be accessed by itself and children.
    IController* _controller;
    
    public:
    BaseComponent(IController* controller = nullptr) // name equals the classname. this is the init method.
        : _controller(controller){}
    
    void set_controller(IController* controller){
        _controller = controller;
    }
};


class Armenians: public BaseComponent{
    public:
    void HostSlavicReunion(){ // погнали!! Let's go!
        std::cout << "Armenians are hosting a slavic reunion!"; // this is just print. std namespace (like a module 'math'). <<, the insertion operator sends text to it.
        _controller->Notify(this, "hosting reunion");
    }

    void RecruitingArmenianCultists(){
        std::cout << "Armenia is recruiting Armenian cultists.";
        _controller->Notify(this, "recruit cultists");
    }

    void SharePostOnLinkedin(){
        std::cout << "Armenia is sharing this post on LinkedIn!";
        _controller->Notify(this, "armenians reposting");
    }

};

class Kazakhs: public BaseComponent{
    public:
    void AttendSlavicReunion(){
        std::cout << "Kazakhs are attending a Slavic reunion!";
        _controller->Notify(this, "attend reunion");
    }

    void SharePostOnLinkedIn(){
        std::cout << "Kazakhs are sharing this post on LinkedIn!";
        _controller->Notify(this, "kazakhs reposting");
    }

    void HostCentralAsianLadiesInitiative(){
        std::cout << "Kazakhs are hosting a Central Asian Ladies Initiative!";
        _controller->Notify(this, "hosting CALI");
    }
};

class TigranTheController: public IController{
    // a concrete controller.
    private: 
    Armenians* armenianCultists;
    Kazakhs* kazakhCultists;

    public:
    TigranTheController(Armenians* am, Kazakhs* kz)
    : armenianCultists(am), kazakhCultists(kz){
        armenianCultists->set_controller(this);
        kazakhCultists->set_controller(this); // the components allow Tigran to control them.
    } // instantiate army

    void Notify(BaseComponent* sender, std::string event) const override{
        std::cout << "Event received: " << event << std::endl;
        if(event == "hosting reunion"){
            kazakhCultists->AttendSlavicReunion();
        }else if(event == "recruit cultists"){
            kazakhCultists->SharePostOnLinkedIn();
        }else if(event == "hosting CALI"){
            armenianCultists->SharePostOnLinkedin();
        }
    }
};


// call the above functions
int main(){
    Armenians* armenianCultists = new Armenians();
    Kazakhs* kazakhCultists = new Kazakhs();
    TigranTheController TigranIII(armenianCultists, kazakhCultists);

    armenianCultists->HostSlavicReunion();
    kazakhCultists->HostCentralAsianLadiesInitiative();

}
