#include "utils.hpp"
//#include "config.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"

namespace checkRoadmap {

    // Look if I am in the Wood lv1 starting roadmap [0,-18].
    bool CheckWoodLv1();

    // Look if I am in the Wood Otomai coast starting roadmap [-48, -19]
    bool CheckOtomaiCoast();

    // Look if I am in the Koalak lake starting roadmap [-16, -3]
    bool CheckKoalaksLagos();

    // Look if I am in the Koalak wood starting roadmap [-11, 1]
    bool CheckKoalaksWood();

    // Look if I am in Tirith [-3, 9]
    bool CheckTirith();

    // Look if I am in Alamo wood Frigost [-75, -49]
    bool CheckAlamo();
}