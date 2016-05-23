/*
  Copyright 2014 Statoil ASA.

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

#include <opm/common/OpmLog/OpmLog.hpp>
#include <opm/common/OpmLog/Logger.hpp>
#include <opm/common/OpmLog/StreamLog.hpp>
#include <iostream>

namespace Opm {


    std::shared_ptr<Logger> OpmLog::getLogger() {
        if (!m_logger)
            m_logger.reset( new Logger() );

        return m_logger;
    }


    void OpmLog::addMessage(int64_t messageFlag , const std::string& message) {
        if (m_logger)
            m_logger->addMessage( messageFlag , message );
    }


    void OpmLog::addTaggedMessage(int64_t messageFlag, const std::string& tag, const std::string& message) {
        if (m_logger)
            m_logger->addTaggedMessage( messageFlag, tag, message );
    }


    void OpmLog::info(const std::string& message)
    {
        addMessage(Log::MessageType::Info, message);
    }


    void OpmLog::warning(const std::string& message)
    {
        addMessage(Log::MessageType::Warning, message);
    }


    void OpmLog::problem(const std::string& message)
    {
        addMessage(Log::MessageType::Problem, message);
    }


    void OpmLog::error(const std::string& message)
    {
        addMessage(Log::MessageType::Error, message);
    }


    void OpmLog::bug(const std::string& message)
    {
        addMessage(Log::MessageType::Bug, message);
    }

    
    void OpmLog::debug(const std::string& message)
    {
        addMessage(Log::MessageType::Debug, message);
    }



    void OpmLog::info(const std::string& tag, const std::string& message)
    {
        addTaggedMessage(Log::MessageType::Info, tag, message);
    }


    void OpmLog::warning(const std::string& tag, const std::string& message)
    {
        addTaggedMessage(Log::MessageType::Warning, tag, message);
    }


    void OpmLog::problem(const std::string& tag, const std::string& message)
    {
        addTaggedMessage(Log::MessageType::Problem, tag, message);
    }


    void OpmLog::error(const std::string& tag, const std::string& message)
    {
        addTaggedMessage(Log::MessageType::Error, tag, message);
    }


    void OpmLog::bug(const std::string& tag, const std::string& message)
    {
        addTaggedMessage(Log::MessageType::Bug, tag, message);
    }


    void OpmLog::debug(const std::string& tag, const std::string& message)
    {
        addTaggedMessage(Log::MessageType::Debug, tag, message);
    }




    bool OpmLog::enabledMessageType( int64_t messageType ) {
        if (m_logger)
            return m_logger->enabledMessageType( messageType );
        else
            return Logger::enabledDefaultMessageType( messageType );
    }

    bool OpmLog::hasBackend(const std::string& name) {
        if (m_logger)
            return m_logger->hasBackend( name );
        else
            return false;
    }


    bool OpmLog::removeBackend(const std::string& name) {
        if (m_logger)
            return m_logger->removeBackend( name );
        else
            return false;
    }


    void OpmLog::removeAllBackends() {
        if (m_logger) {
            m_logger->removeAllBackends();
        }
    }


    void OpmLog::addMessageType( int64_t messageType , const std::string& prefix) {
        auto logger = OpmLog::getLogger();
        logger->addMessageType( messageType , prefix );
    }


    void OpmLog::addBackend(const std::string& name , std::shared_ptr<LogBackend> backend) {
        auto logger = OpmLog::getLogger();
        return logger->addBackend( name , backend );
    }



    void OpmLog::setupSimpleDefaultLogging(const bool use_prefix)
    {
         std::shared_ptr<StreamLog> streamLog = std::make_shared<StreamLog>(std::cout, Log::DefaultMessageTypes);
         OpmLog::addBackend( "SimpleDefaultLog", streamLog);
         streamLog->setMessageLimiter(std::make_shared<MessageLimiter>(10));
         streamLog->setMessageFormatter(std::make_shared<SimpleMessageFormatter>(use_prefix, true));
    }
/******************************************************************/

    std::shared_ptr<Logger> OpmLog::m_logger;
}