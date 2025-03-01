/*#include <cppconn/driver.h>

int main()
{
    sql::Driver *driver;
    driver = get_driver_instance();
}
*/

/* Standard C++ includes */
#include "main.h"

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main (void)
{
cout << endl;
cout << "Running 'Le truc'..." << endl;

try {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "isen", "isen29");
  /* Connect to the MySQL test database */
  con->setSchema("inventaire");

  stmt = con->createStatement();
  res = stmt->executeQuery("SELECT * FROM articles;");
  while (res->next()) { // fetch
    /* Access column data by alias or column name */
    cout << res->getInt(1) << '\t';
    cout << res->getString(2) << '\t' << '\t';
    cout << res->getInt(3) << endl;
  }
  delete res;
  delete stmt;
  delete con;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;

return EXIT_SUCCESS;
}

int main()
{
  try
  {
    GestionBDD bdd(/*paramètres de connection*/);
    bdd.listerArticles();

  }
  catch(const sql::SQLException &e)
  {
    cout << "Erreur :" << e.what();
    cout << "Code Erreur Mysql : " << e.getErrorCode() << endl;
  }
  return 0;
}