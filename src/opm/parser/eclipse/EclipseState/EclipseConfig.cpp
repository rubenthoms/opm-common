/*
 Copyright 2016 Statoil ASA.

 This file is part of the Open Porous Media project (OPM).

 OPM is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 OPM is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with OPM.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <memory>

#include <opm/parser/eclipse/Deck/Deck.hpp>
#include <opm/parser/eclipse/Deck/DeckSection.hpp>
#include <opm/parser/eclipse/EclipseState/EclipseConfig.hpp>
#include <opm/parser/eclipse/EclipseState/InitConfig/InitConfig.hpp>
#include <opm/parser/eclipse/EclipseState/IOConfig/IOConfig.hpp>
#include <opm/parser/eclipse/EclipseState/IOConfig/RestartConfig.hpp>

namespace Opm {

    EclipseConfig::EclipseConfig(const Deck& deck, const ParseContext& parseContext, ErrorGuard& errors) :
            m_initConfig(      deck),
            m_restartConfig(   deck, parseContext, errors )
    {
    }


    EclipseConfig::EclipseConfig(const InitConfig& initConfig,
                                 const RestartConfig& restartConfig) :
        m_initConfig(initConfig),
        m_restartConfig(restartConfig)
    {
    }


    const InitConfig& EclipseConfig::init() const {
        return m_initConfig;
    }

    const IOConfig& EclipseConfig::io() const {
        return this->m_restartConfig.ioConfig();
    }

    IOConfig& EclipseConfig::io() {
        return this->m_restartConfig.ioConfig();
    }

    const RestartConfig& EclipseConfig::restart() const {
        return this->m_restartConfig;
    }

    // [[deprecated]] --- use restart()
    const RestartConfig& EclipseConfig::getRestartConfig() const {
        return this->restart();
    }

    // [[deprecated]] --- use init()
    const InitConfig& EclipseConfig::getInitConfig() const {
        return init();
    }

    bool EclipseConfig::operator==(const EclipseConfig& data) const {
        return this->init() == data.init() &&
               this->restart() == data.restart();
    }

}
