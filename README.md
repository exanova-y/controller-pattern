This repo implements a simple c**ontroller-mediator** pattern. 

To explain with an example, we have some Armenian and Kazakh cultists. Behind the scenes, is the orchestrator Tigran the Third.

1. When Armenians host a Slavic reunion, they notify Tigran, who then notifies the Kazakh cultists to attend. 
2. When Kazakhs host a Central Asian Ladies Initiative, they notify Tigran, who then notifies the Armenian cultists to repost on LinkedIn.

Extracting the pattern, the mediator components notify the controller, which then notifies the other components. Both components inherit from base components. 


To run, use `g++ main.cpp -o a` to compile, then `./a` to execute