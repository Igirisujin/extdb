/*
Copyright (C) 2014 Declan Ireland <http://github.com/torndeco/extDB>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/



#pragma once

#include <Poco/Data/SessionPool.h>
#include <boost/shared_ptr.hpp>

#ifdef LOGGING
	#include <boost/log/core.hpp>
	#include <boost/log/trivial.hpp>
	#include <boost/log/utility/setup/file.hpp>
	#include <boost/log/sources/severity_logger.hpp>
	#include <boost/log/sources/record_ostream.hpp>
#endif
#include <iostream>
#include <cstdlib>

#include "abstract_ext.h"

class AbstractProtocol
{
	public:
		AbstractProtocol();
		virtual ~AbstractProtocol();
		virtual void callProtocol(AbstractExt *extension, std::string input_str, std::string &result)=0;
		virtual bool init(AbstractExt *extension);

	#ifdef LOGGING
		protected:
			boost::log::sources::severity_logger_mt< boost::log::trivial::severity_level > logger;
	#endif
};
