/*
** Copyright (C) 2014 Cisco and/or its affiliates. All rights reserved.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License Version 2 as
** published by the Free Software Foundation.  You may not use, modify or
** distribute this program under any other version of the GNU General
** Public License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

// cd_vlan_module.cc author Josh Rosenbaum <jrosenba@cisco.com>

#include "codecs/link/cd_vlan_module.h"


static const Parameter vlan_params[] =
{
    { nullptr, Parameter::PT_MAX, nullptr, nullptr, nullptr }
};


static const RuleMap vlan_rules[] =
{
    { DECODE_BAD_VLAN, "(" CD_VLAN_NAME ") Bad VLAN Frame" },
    { DECODE_BAD_VLAN_ETHLLC, "(" CD_VLAN_NAME ") Bad LLC header" },
    { DECODE_BAD_VLAN_OTHER, "(" CD_VLAN_NAME ") Bad Extra LLC Info" },
    { 0, nullptr }
};

//-------------------------------------------------------------------------
// rpc module
//-------------------------------------------------------------------------

VlanModule::VlanModule() : DecodeModule(CD_VLAN_NAME, vlan_params, vlan_rules)
{ }

bool VlanModule::set(const char*, Value&, SnortConfig*)
{
    return true;
}
