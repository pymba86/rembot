#pragma once

#include <memory>
#include <condition_variable>
#include <mutex>

namespace rb {

    struct StateData;
    struct StateInput;

    class Core {
    public:
        Core();
        ~Core();


        void init();

        void update();

        void exit();

        std::weak_ptr<StateData> getStateData() const;

        void setStateInput(std::weak_ptr<StateInput> stateInput);

        enum Event {
            Close,
            Init,
            Disconnect,
            DataOn,
            DataOff
        };

        void notifyEvent(Event event);

    private:
        void input();
        void main();
        void cache();

        struct Data;
        std::unique_ptr<Data> _data;
    };
}