#include <iostream>
#include <map>

using std::string, std::cout, std::endl;

class Module {
public:
    // Получить имя модуля
    virtual string getName() const = 0;

    // Запустить модуль
    virtual void run() = 0;
};

class ModuleA : public Module {
public:
    string getName() const {
        return "moduleA";
    }

    void run() {
        cout << "ModuleA runs" << endl;
    }
};

class ModuleB : public Module {
public:
    string getName() const {
        return "moduleB";
    }

    void run() {
        cout << "ModuleB runs" << endl;
    }
};

class Dispatcher {
public:
    // Зарегистрировать переданный модуль
    void registerModule(Module* m) {
        auto moduleName = m->getName();
        modules[moduleName] = m;
    }

    // Вызвать метод run для модуля с именем moduleName
    // Если такого модуля не зарегистрировано, ничего не делать (но не падать)
    void runModule(const string moduleName) const {
        auto found_iterator = modules.find(moduleName);
        if (found_iterator != modules.end()) {
            auto& module_ptr = found_iterator->second;
            module_ptr->run();
        }
    }

private:
    std::map<string, Module*> modules;
};

int main()
{
    Module* m1 = new ModuleA();
    Module* m2 = new ModuleB();

    Dispatcher d;
    d.registerModule(m1);
    d.registerModule(m2);
    d.runModule("moduleA");
    d.runModule("moduleB");
    d.runModule("moduleC");

    delete m1;
    delete m2;

    return 0;
}