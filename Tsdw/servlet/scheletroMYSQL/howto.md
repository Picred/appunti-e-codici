### Build scheletro app
- uso `mvn archetype:generate -DarchetypeGroupId=org.apache.maven.archetypes -DarchetypeArtifactId=maven-archetype-webapp -DarchetypeVersion=1.4` per buildare e avere `src` e `pom.xml`
    - Come groupID e artifactID: ho messo *scheletro*
- Con `mvn install` usato ho anche `target`
- Visto che voglio usare **Jetty**, metto il suo plugin nel `pom.xml`:
```xml
<plugin>
<groupId>org.eclipse.jetty</groupId>
<artifactId>jetty-maven-plugin</artifactId>
<configuration>
<scan>10</scan>
</configuration>
</plugin>
```
- Uso `mvn jetty:run`
- Collegandomi a `localhost:8080` vedo *Hello World*

- Aggiungo la dipendenza dalle servlet nelle dipendenze del `pom.xml`
```xml
<dependency>  
	<groupId>jakarta.servlet</groupId>  
	<artifactId>jakarta.servlet-api</artifactId>  
	<version>6.0.0</version>  
	<scope>provided</scope>  
</dependency>
```
- Creo la classe `.java` che farà da Servlet
- Aggiungo a `web.xml` il **MAPPING SERVLET**
```xml
<servlet>
    <servlet-name>Scheletro</servlet-name>
    <servlet-class>Scheletro</servlet-class>
</servlet>

  <servlet-mapping>
    <servlet-name>Scheletro</servlet-name>
  <url-pattern>/scheletro</url-pattern>
  </servlet-mapping>
```

# Scheletro COMPLETATO (forse)

# Come usare MYSQL
- Aggiungo la dipendenza a `mysql-connector-java`

```xml
<dependency>
    <groupId>com.mysql</groupId>
	<artifactId>mysql-connector-j</artifactId>
	<version>8.2.0</version>
</dependency>

```

- Aggiungo nella servlet:

```java

import java.sql.Connection
import java.sql.DriveManager
import java.sql.SQLException

// Class HelloWorld extends HTttpServlet
Connection connnection;  
final String connectionString = "jdbc:mysql://localhost:3306/DBNAME?user=USERNAME&password=PASSWORD";

public void init() {  
        System.out.println("Servlet " + this.getServletName() + " has started");  
        try {  
             connnection = DriverManager.getConnection(connectionString);  
        } catch (SQLException e) {  
            // This print goes into catalina.out or standard output with Jetty  
            System.out.println("Error while connecting to database");  
            System.out.println("SQLException: " + e.getMessage());  
            System.out.println("SQLState: " + e.getSQLState());  
            System.out.println("VendorError: " + e.getErrorCode());  
            return;  
        }  
        System.out.println("Connection Successfull");  
    }
```