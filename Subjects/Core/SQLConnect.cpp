//#include <stdlib.h>
//#include "SQLConnect.h"
//#include <iostream>
//#include "SDKs\mysql\include\mysql_connection.h"
//#include <SDKs\mysql\include\cppconn\driver.h>
//#include <SDKs\mysql\include\cppconn\exception.h>
//#include <SDKs\mysql\include\cppconn\resultset.h>
//#include <SDKs\mysql\include\cppconn\statement.h>
//
//bool CSQLConnect::Connect() {
//
//	sql::Driver *driver;
//	sql::Connection *connection;
//	sql::Statement *statement;
//
//	driver = get_driver_instance();
//
//	try {
//
//		connected = connection != NULL && (connection->isValid() || connection->reconnect());
//
//		if (!connected) {
//
//			connection = driver->connect("tcp://mysql.hostinger.se:3306", "u178586788_admin", "Ville123"); //Server, UserID, Password
//			connected = connection->isValid();
//
//		}
//
//		if (connected) {
//
//			statement = connection->createStatement();
//			char str[255];
//			sprintf(str, "USE %s", "u178586788_lvpl"); //Database
//			statement->execute(str);
//			return true;
//
//		}
//
//	} catch (sql::SQLException &e) {
//
//		delete connection;
//		connection = NULL;
//		return false;
//
//	}
//
//}