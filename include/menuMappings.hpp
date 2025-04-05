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
    SILBO          = 1 +'0',
    BORRASCA       = 2 +'0',
    ESCALOFRIO     = 3 +'0',
    MANIOBRA       = 4 +'0',
    PASTO          = 5 +'0',
    MOON           = 6 +'0',
    LLAMILLA       = 7 +'0',
    NATURAL        = 8 +'0',
    RECELO         = 9 +'0',
    VIGIA          = 0 +'0',
    REFUGIO        = 11,
    REAGRUPAMIENTO = 12,
    SPELLS_ROW     = true
};

enum SpellsCtrlRow {
    MURALLA         = 1 +'0',
    ESCUDO          = 2 +'0',
    BASTION         = 3 +'0',
    BARRICADA       = 4 +'0',
    TELEPORT        = 5 +'0',
    ATARAXIA        = 6 +'0',
    ESCARCHA        = 7 +'0',
    POMPA           = 8 +'0',
    ESCAPADITA      = 9 +'0',
    ESTRATO         = 0 +'0',
    DOMINIO         = 11,
    WEAPON          = 'q',
    SPELLS_CTRL_ROW = false
};