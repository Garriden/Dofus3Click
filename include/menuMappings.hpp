#pragma once

//////////////////////////////////
// SPELLS MAPPING
//////////////////////////////////

// FECA AIR
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   1       2          3         4      5    6      7       8     9      0       '         ¡
//-------------------------------------------------------------------------------------------------------
// Silbo  Borrasca Escalofrío Maniobra Pasto Moon Llamilla Gravi Recelo Vigía Refugio Reagrupamiento
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
// ctrl+1  ctrl+2  ctrl+3  ctrl+4  ctrl+5 ctrl+6   ctrl+7  ctrl+8  ctrl+9    ctrl+0      ctrl+'     q
//-------------------------------------------------------------------------------------------------------
// Muralla Escudo Bastión Barricada Tele Refuerzo Escarcha Pompa Escapadita Magnetismo Dominio CaC(Pala)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum SpellsRow {
    SILBO          = 1,
    BORRASCA       = 2,
    ESCALOFRIO     = 3,
    MANIOBRA       = 4,
    PASTO          = 5,
    MOON           = 6,
    LLAMILLA       = 7,
    GRAVI          = 8,
    RECELO         = 9,
    VIGIA          = 0,
    REFUGIO        = 11,
    REAGRUPAMIENTO = 12
};

enum SpellsCtrlRow {
    MURALLA        = 1,
    ESCUDO         = 2,
    BASTION        = 3,
    BARRICADA      = 4,
    TELEPORT       = 5,
    REFUERZO       = 6,
    ESCARCHA       = 7,
    POMPA          = 8,
    ESCAPADITA     = 9,
    MAGNETISMO     = 10,
    DOMINIO        = 11,
    WEAPON         = 12
};