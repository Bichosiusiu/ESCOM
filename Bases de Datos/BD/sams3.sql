-- MySQL dump 10.13  Distrib 5.1.31, for Win32 (ia32)
--
-- Host: localhost    Database: sams
-- ------------------------------------------------------
-- Server version	5.1.31-community

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `club`
--

DROP TABLE IF EXISTS `club`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `club` (
  `idClub` int(10) unsigned NOT NULL,
  `nombre` varchar(45) NOT NULL,
  `direccion` varchar(150) NOT NULL,
  `tel` varchar(45) NOT NULL,
  `edo` varchar(30) NOT NULL,
  PRIMARY KEY (`idClub`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `club`
--

LOCK TABLES `club` WRITE;
/*!40000 ALTER TABLE `club` DISABLE KEYS */;
INSERT INTO `club` VALUES (103,'Cuernavaca','Autopista Mex – Acapulco Km. 87.85 Esq. Av. 50 Metros s/n Col. Ricardo Flores Magón 5tp Fracc. C.P. 62370. Cuernavaca. Mor','01(777)1-00-74-00','Morelos'),(104,'Puebla','Av. Del Niño Poblano No. 2510. Concepción de la Cruz C.P. 72430. Puebla, Pue.','01(222)2-29-75-00','Puebla'),(105,'Guadalajara','Av. Rafael Sandio No. 159 Int. 204 C.P. 45020 Col. Vallarta Camichines. Zapopan, Jal.','01(33)37-77-22-00','Jalisco'),(106,'Satelite','Circuito Centro Comercial No. 2251. Col. Ciudad Satélite C.P. 53100 Naucalpan Edo. de México.','01(55)57-29-31-00','Edo. de Mexico'),(108,'Pachuca','Camino Real de la Plata No. 100 Col. Zona Plateada C.P. 42080. Pachuca, Hgo.','01(771)7-17-88-99','Hidalgo'),(120,'Perisur','Periférico Sur No. 4690 Col. Ampl. Pedregal de San Ángel C.P. 04500 Coyoacán, DF.','01(55)54-47-12-00','DF'),(143,'Insurgentes','Insurgentes sur No. 1310 Col. Del Valle C.P. 03100 Benito Juárez. DF.','01(55)54-80-13-00','DF'),(157,'Lindavista','Colector 13 No. 280 Col. Magdalena de las Salinas. C.P. 07760, Gustavo A. Madero. DF','01(55)57-47-10-00','DF'),(176,'Merida','Calle 60 No. 299 Carr. Mérida-Progreso Km. 8.5 Col. Revolución C.P. 97110 Mérida. Yuc.','01(999)9-42-72-00','Yucatán');
/*!40000 ALTER TABLE `club` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gerente`
--

DROP TABLE IF EXISTS `gerente`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `gerente` (
  `idGerente` int(10) unsigned NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `idClub` int(10) unsigned NOT NULL,
  PRIMARY KEY (`idGerente`),
  KEY `FK_gerente_1` (`idClub`),
  CONSTRAINT `FK_gerente_1` FOREIGN KEY (`idClub`) REFERENCES `club` (`idClub`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `gerente`
--

LOCK TABLES `gerente` WRITE;
/*!40000 ALTER TABLE `gerente` DISABLE KEYS */;
INSERT INTO `gerente` VALUES (101,'AGUIRRE MARTINEZ ISRAEL',103),(102,'BARUCH BALDERRAMA ANGEL',104),(103,'DIAZ GUTIERREZ PEDRO',105),(104,'FERNANDEZ BENITEZ ELIZABETH',108),(105,'GONZALEZ LOPEZ ALAN',106),(106,'LARA CARDENAS URIEL MAURICIO',120),(107,'LOPEZ GARCIA JAVIER',143),(108,'LOPEZ PADILLA DIEGO GERARDO',157),(109,'MORANTE TORRECILLAS JARITH ALY',176),(110,'OCHOA GARCIA HECTOR GABRIEL',103),(111,'RONQUILLO GIL MIGUEL ANGEL',104),(112,'RUIZ VICTORIA HUGO IVAN',105),(113,'VAZQUEZ PEREZ FERMIN TEUCTZINTLI',108),(114,'ZUNIGA SANCHEZ GERARDO',106),(115,'BALLESTEROS HERNANDEZ YOSELIN ANDREA',103),(116,'BARRIENTOS AGUILAR MARCO VINICIO',104),(117,'CANO MARTINEZ ADRIAN',105),(118,'CEVANTES ROMERO DOLORES',106),(119,'CHIA ACOSTA JORGE ALBERTO',108),(120,'DAVALOS GUIZAR HECTOR IVAN',120),(121,'DE LA ROSA MERCADO MARCO ANTONIO',143),(122,'DIMAS PEREZ JUAN RAMON',157),(123,'ESCAMILLA ARROYO ANGEL',176),(124,'ESTRADA GONZALEZ MARIA LUISA',103),(125,'GALVAN HERNANDEZ MARIA ISABEL',104),(126,'GARCIA CRUZ JOSE LUIS',105),(127,'GARCIA REYES NEFTALI',106),(128,'GODINEZ VAZQUEZ ELVIA',108),(129,'GOMEZ GODINEZ  GUADALUPE ALEJANDRA',120),(130,'GOMEZ GODINEZ SALVADOR MANUEL',143),(131,'GONZALEZ ARCEO BELEM IRERI',157),(132,'GONZALEZ HIPOLITO SERGIO ANDRES',176),(133,'GRACIAN HERNANDEZ SERGIO DEMIAN',103),(134,'GUERRERO TELLEZ JORGE',104),(135,'GUZMAN RIVERA MARCELA',105),(136,'HERNANDEZ AGUILAR CARLOS ALBERTO',106),(137,'HERNANDEZ ALAMILLA MIGUEL ANGEL',108),(138,'HERNANDEZ LOPEZ FILEMON',120),(139,'HERRERA HERNANDEZ JENIFFER',143),(140,'LARA HERNANDEZ ADRIANA',157),(141,'LICONA PEREZ NANCY YOLONTZIN',176),(142,'LOPEZ ISLAS MARIANA',103),(143,'LOPEZ LOPEZ MARCIAL',104),(144,'LOPEZ MARTINEZ HUGO',105),(145,'LUNA CRUZ DAVID',106),(146,'MARTINEZ CASTILLO MARIA REYNA',108),(147,'NARVAEZ FLORES MIREYA',120),(148,'NORIEGA GARCIA JORGE',143),(149,'OLGUIN FRIAS ANGEL GERONIMO',157),(150,'PELAEZ GIL RICARDO',176),(151,'PEREZ HUEBE MA. DE LOURDES',103),(152,'RAMIREZ AOKI GERARDO',104),(153,'REYES BELTRAN JUANA',105),(154,'RUIZ ALCANTARA ADA HAZAEL',106),(155,'SANCHEZ TAPIA CARLOS',108),(156,'SAUZA JIMENEZ DAMIAN',120),(157,'SOTO MC.NAUGTH ROCIO EDITH',143),(158,'TAPIA LOPEZ ARIANNA YANET',157),(159,'TELLEZ CORELLA PEDRO IVAN',176),(160,'TOVAR ESCORZA DENISSE',103),(161,'VALDEZ DOMINGUEZ LUIS',104),(162,'VARGAS MARTINEZ BLANCA ELIZABETH',105),(163,'VERTIZ HERNANDEZ CARLOS',106),(164,'VILLAMIL ESCUDERO MIRIAM',108),(165,'VILLEGAS LARA MAGIN',120),(167,'AGUILERA LUNA ORESTES JOB',103),(168,'BRITO CRUZ CARLOS EMMANUEL',105),(169,'CASTILLO GONZALEZ IVAN',106),(170,'CHAVEZ CRUZ DANIEL',108),(171,'COSIO MARTINEZ LUIS EDGAR',120),(172,'CRUZ CARLIN EFREN',143),(173,'ESPARZA GUERRERO LAURA EUNICE',157),(174,'GARCIA TORBELLIN RODRIGO',176),(175,'GOMEZ MARTINEZ MIRIAM AIDE',103),(176,'GONZALEZ ZAVALA HUGO CESAR',104),(177,'HERNANDEZ ORTIZ JESUS',105),(178,'HERRERA MARIN FRANCISCA',106),(179,'ISIDRO RAMIREZ RICARDO',108),(180,'JUAREZ MERCADO JUAN CARLOS',120),(181,'LEYRA LEON JONATHAN JORGE',143),(182,'LOPEZ HERNANDEZ YAZMIN SARAHI',157),(183,'LOPEZ OBREGON ERIKA LISSETTE',176),(184,'MARMOLEJO JIMENEZ ERICK IVAN',103),(185,'NAVARRETE RODRIGUEZ ROSA MARIA',104),(186,'ORTIZ JIMENEZ RAUL',105),(187,'PAZ GARCIA NOE MISAEL',106),(188,'PEDRAZA ALCALA JUAN CARLOS',108),(189,'RAMOS ACEVEDO GERMAN MANUEL',120),(190,'RINCON PEREZ JOSE ANTONIO',143),(191,'RIVERA GUILLEN DIEGO',157),(192,'RUIZ GUTIERREZ MARCO ANTONIO',176),(193,'SAGRERO DE LA CRUZ JONATHAN ISRAEL',103),(194,'SALAZAR NAVARRETE ALEJANDRO',104),(195,'SALAZAR OLGUIN LUCIA ALEJANDRA',105),(196,'SANCHEZ ALVAREZ LUIS',106),(197,'SANCHEZ ELIZALDE LIZBETH YESENIA',108),(198,'SANCHEZ VILLANUEVA JUAN',120),(199,'SANTOS ATENCO ADAN',143),(200,'TIZCAREÑO CERDA ANA BEATRIZ',157),(201,'URBINA JUAN JOSE MIGUEL',176);
/*!40000 ALTER TABLE `gerente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `producto`
--

DROP TABLE IF EXISTS `producto`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `producto` (
  `idProducto` int(10) unsigned NOT NULL,
  `nombre` varchar(45) NOT NULL,
  `idProveedor` int(10) unsigned NOT NULL,
  `precioUnitario` double NOT NULL,
  PRIMARY KEY (`idProducto`),
  KEY `FK_producto_1` (`idProveedor`),
  CONSTRAINT `FK_producto_1` FOREIGN KEY (`idProveedor`) REFERENCES `proveedor` (`idProveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `producto`
--

LOCK TABLES `producto` WRITE;
/*!40000 ALTER TABLE `producto` DISABLE KEYS */;
INSERT INTO `producto` VALUES (1,'Galletas Lara Salada',22,30.9),(2,'Galletas Lara Dulce',22,21.9),(3,'Galletas Lara Saludable',22,26.6),(4,'Barcel Chips',22,3.99),(5,'Barcel Hot Nuts',22,2.99),(6,'Marinela Gansito',22,5),(7,'Marinela Pinguino',22,6),(8,'Marinela Submarino',22,6.95),(9,'Ricolino Bubulubu',22,12.95),(10,'Ricolino Paleta Payaso',22,8.45),(11,'Ricolino Kranky',22,6.3),(12,'Coronado Cajeta Vainilla',22,51.5),(13,'Coronado Cajeta Quemada',22,51.5),(14,'Coronado Cajeta Envinada',22,51.5),(15,'Suandy Galletas',22,13.9),(16,'Suandy Pasteles',22,57.35),(17,'Tia Rosa Bigotes',22,4.5),(18,'Tia Rosa Doraditas',22,5),(19,'Tia Rosa Empanadas',22,18.9),(20,'Tia Rosa Conchas',22,7),(21,'Tia Rosa Semitas',22,11.9),(22,'Tia Rosa Orejas',22,6),(23,'Tia Rosa Tortillinas',22,14.9),(24,'Sabritas Poffets',24,4.35),(25,'Sabritas Rancheritos',24,4.32),(26,'Sabritas Sabritones',24,4.55),(27,'Sabritas Sun Chips',24,4.55),(28,'Sabritas Tacos',24,4.35),(29,'Sabritas Tacos',24,4.53),(30,'Sabritas Tradicionales',24,4.55),(31,'Sabritas Churrumais',24,4.53),(32,'Sabritas Crujitos',24,4.55),(33,'Sabritas Fritos',24,4.32),(34,'Sabritas Rufles',24,4.32),(35,'Sabritas Doritos Nacho',24,4.52),(36,'Sabritas Cheetos',24,4.52),(37,'Axion Liquido',25,23.92),(38,'Axion Polvo',25,18.4),(39,'Axion Pasta',25,21.2),(40,'Ajax Bicloro',25,23.82),(41,'Ajax Spray',25,21.2),(42,'Ajax Fibras',25,21.2),(43,'Fabuloso Liquido',25,11.75),(44,'Magitel',25,19.5),(46,'Sony Bravia Full HD',27,17998),(47,'Sony Bravia',27,4699),(48,'Sony Televisor WEGA',27,15498),(49,'Sony PlayStation 3',27,8699),(50,'Sony PSP',27,3799),(51,'Horno Microondas AGE1072',30,1349),(52,'Horno Microondas AGE107W',30,1999),(53,'Refrigerador 4 puertas',30,4490),(54,'Refrigerador Side by Side',30,8999),(55,'Refrigerador Bottom Freezer',30,7299),(56,'Lavadora Carga Frontal WD6122CKC',30,6099),(57,'Lavadora Carga Frontal DV337AGG',30,7599),(58,'Lavadora Automatica WA90U3',30,8599),(59,'LG Celular GSM ME970',32,2322.42),(60,'LG Celular GSM ME230',32,4600),(61,'LG Celular GSM MG160',32,5129),(62,'Pasta Ojito',33,3.79),(63,'Pasta Letra',33,3.79),(64,'Pasta Lenteja',33,3.79),(65,'Pasta Estrella',33,3.79),(66,'Pasta Engrane',33,3.79),(67,'Pasta Monito',33,3.79),(68,'Pasta Fideo 0',33,4.2),(69,'Pasta Fideo 1',33,4.2),(70,'Pasta Fideo 2',33,4.2),(71,'Pasta Corta Codo 1',33,4.29),(72,'Pasta Corta Codo 2',33,4.29),(73,'Pasta Corta Caracol 1',33,4.1),(74,'Pasta Corta Caracol 2',33,4.1),(75,'Pasta Corta Tornillo',33,4.1),(76,'Pasta Larga Spaguetti Italiano',33,4.4),(77,'Pasta Larga Fetuccine',33,4.4),(78,'Sopa Milunch Camaron Picante',33,19.8),(79,'Sopa Milunch Camaron ',33,19.8),(80,'Sopa Milunch Pollo',33,19.8),(81,'Sopa Milunch Res',33,19.8);
/*!40000 ALTER TABLE `producto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proveedor`
--

DROP TABLE IF EXISTS `proveedor`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `proveedor` (
  `idProveedor` int(10) unsigned NOT NULL,
  `nombre` varchar(45) NOT NULL,
  `tel` varchar(25) NOT NULL,
  PRIMARY KEY (`idProveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `proveedor`
--

LOCK TABLES `proveedor` WRITE;
/*!40000 ALTER TABLE `proveedor` DISABLE KEYS */;
INSERT INTO `proveedor` VALUES (22,'Grupo Bimbo S.A de C.V.','01(55)52-68-65-85'),(24,'Sabritas','01(55)52-02-73-73'),(25,'Colgate-Palmolive','01(800)001-1400'),(27,'Sony Mexico','01(55)57-59-85-25'),(30,'Samsung Electronics Mexico','01(55)57-59-85-25'),(32,'LG Electronics México','01(55)57-58-67-56'),(33,'Grupo La Moderna','01(772)279-79-01');
/*!40000 ALTER TABLE `proveedor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proveedorsams`
--

DROP TABLE IF EXISTS `proveedorsams`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `proveedorsams` (
  `idClub` int(10) unsigned NOT NULL,
  `idProveedor` int(10) unsigned NOT NULL,
  PRIMARY KEY (`idClub`,`idProveedor`),
  KEY `FK_proveedorsams_2` (`idProveedor`),
  CONSTRAINT `FK_proveedorsams_1` FOREIGN KEY (`idClub`) REFERENCES `club` (`idClub`),
  CONSTRAINT `FK_proveedorsams_2` FOREIGN KEY (`idProveedor`) REFERENCES `proveedor` (`idProveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `proveedorsams`
--

LOCK TABLES `proveedorsams` WRITE;
/*!40000 ALTER TABLE `proveedorsams` DISABLE KEYS */;
INSERT INTO `proveedorsams` VALUES (103,22),(104,22),(108,22),(120,22),(157,22),(104,24),(108,24),(143,24),(176,24),(103,25),(105,25),(108,25),(120,25),(105,27),(106,27),(143,27),(157,27),(176,27),(104,30),(105,30),(106,30),(120,30),(176,30),(103,32),(104,32),(106,32),(143,32),(157,32),(103,33),(104,33),(105,33),(106,33),(108,33),(120,33),(143,33),(157,33),(176,33);
/*!40000 ALTER TABLE `proveedorsams` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `socio`
--

DROP TABLE IF EXISTS `socio`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `socio` (
  `idSocio` int(10) unsigned NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `direccion` varchar(100) NOT NULL,
  `tel` varchar(15) NOT NULL,
  PRIMARY KEY (`idSocio`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `socio`
--

LOCK TABLES `socio` WRITE;
/*!40000 ALTER TABLE `socio` DISABLE KEYS */;
INSERT INTO `socio` VALUES (1,'ANGELES DE LA CRUZ ANDREE MICHEL IRVING','Av. Juarez. s/n','554-234-5555'),(2,'ARMENDARIZ CRUZ OCTAVIO ARTURO','Av. Juarez. s/n','554-234-5555'),(3,'CARVAJAL MURILLO ANA VICTORIA','Av. Juarez. s/n','554-234-5555'),(4,'CASTAÑEDA GONZALEZ LEONARDO MAURICIO','Av. Juarez. s/n','554-234-5555'),(5,'CASTILLO GONZALEZ IVAN','Av. Juarez. s/n','554-234-5555'),(6,'CRUZ CHAVEZ EDGAR DANIEL','Av. Juarez. s/n','554-234-5555'),(7,'FLORES GALICIA OMAR ISAIAS','Av. Juarez. s/n','554-234-5555'),(8,'GARCIA CERVANTES ANEL','Av. Juarez. s/n','554-234-5555'),(9,'GARCIA MORA OSVALDO','Av. Juarez. s/n','554-234-5555'),(10,'GOMEZ TETLALMATZI JESSICA','Av. Juarez. s/n','554-234-5555'),(11,'GONZALEZ ZAVALA HUGO CESAR','Av. Juarez. s/n','554-234-5555'),(12,'GUZMAN RIOS RAFAEL ANGEL','Av. Juarez. s/n','554-234-5555'),(13,'HERNANDEZ ESTRADA ALAN YESSAHIR','Av. Juarez. s/n','554-234-5555'),(14,'HERNANDEZ ROSAS DANIEL ALEJANDRO','Av. Juarez. s/n','554-234-5555'),(15,'LOPEZ OBREGON ERIKA LISSETTE','Av. Juarez. s/n','554-234-5555'),(16,'MONROY MORAN SERGIO ISRAEL','Av. Juarez. s/n','554-234-5555'),(17,'NAJER GONZALEZ LESSLYE ALY','Av. Juarez. s/n','554-234-5555'),(18,'OVIEDO ESPINOZA JOSAFAT','Av. Juarez. s/n','554-234-5555'),(19,'PEREZ MORALES MARCELA','Av. Juarez. s/n','554-234-5555'),(20,'PIMENTEL MARTINEZ WALDO','Av. Juarez. s/n','554-234-5555'),(21,'RAMIREZ JIMENEZ ALLAN CESAR','Av. Juarez. s/n','554-234-5555'),(22,'RAMIREZ MARTINEZ ERICK DANIEL','Av. Juarez. s/n','554-234-5555'),(23,'RIOS GASPAR IZCHEL NAYELI','Av. Juarez. s/n','554-234-5555'),(24,'RODRIGUEZ MARTINEZ ARTURO','Av. Juarez. s/n','554-234-5555'),(25,'ROMERO GALVAN LUIS ROBERTO','Av. Juarez. s/n','554-234-5555'),(26,'SANCHEZ MONROY OMAR ISRAEL','Av. Juarez. s/n','554-234-5555'),(27,'SORIA HIDALGO MANUEL ALEJANDRO','Av. Juarez. s/n','554-234-5555'),(28,'VAZQUEZ CARAVANTES EDUARDO','Av. Juarez. s/n','554-234-5555'),(29,'VILLA RUSSELL JUAN PABLO','Av. Juarez. s/n','554-234-5555'),(30,'LAGOS CAXNAJOY EDGAR JACOBO','Av. Juarez. s/n','554-234-5555'),(31,'ESPINOZA GIL ADALID','Av. Juarez. s/n','554-234-5555'),(32,'ANGELES RODRIGUEZ EDUARDO NERI','Av. Juarez. s/n','554-234-5555'),(33,'BECERRA ABARCA ALBERTO ISAIAS','Av. Juarez. s/n','554-234-5555'),(34,'BONILLA SANCHEZ MAURICIO EDUARDO','Av. Juarez. s/n','554-234-5555'),(35,'DEGOLLADO HERNANDEZ DANIEL','Av. Juarez. s/n','554-234-5555'),(36,'DEL PUERTO ZAMORA JULIO ALBERTO','Av. Juarez. s/n','554-234-5555'),(37,'DIAZ ARROYO SERGIO','Av. Juarez. s/n','554-234-5555'),(38,'DOMINGUEZ PALACIOS GERSON ISAAC','Av. Juarez. s/n','554-234-5555'),(39,'DURAND GONZALEZ ALDO','Av. Juarez. s/n','554-234-5555'),(40,'ESCARCEGA JAIME ANGEL OMAR','Av. Juarez. s/n','554-234-5555'),(41,'ESCOBAR PEREZ MIGUEL ANGEL','Av. Juarez. s/n','554-234-5555'),(42,'ESPINOSA BOYZO VICTOR','Av. Juarez. s/n','554-234-5555'),(43,'GARCIA MARTINEZ JESE ANDRES','Av. Juarez. s/n','554-234-5555'),(44,'GARCIA TORBELLIN RODRIGO','Av. Juarez. s/n','554-234-5555'),(45,'GIL PEREZ ANGEL ARMANDO','Av. Juarez. s/n','554-234-5555'),(46,'GONZALEZ DIAZ MARTIN AUGUSTO','Av. Juarez. s/n','554-234-5555'),(47,'GONZALEZ SANCHEZ MARS YUREN','Av. Juarez. s/n','554-234-5555'),(48,'GUERRERO ANDONAEGUI GABRIEL','Av. Juarez. s/n','554-234-5555'),(49,'HORTA GASCA KARLA JANIRA','Av. Juarez. s/n','554-234-5555'),(50,'LARA RUBI JULIO CESAR','Av. Juarez. s/n','554-234-5555'),(51,'LINARES ARVIZU JOSE DANIEL','Av. Juarez. s/n','554-234-5555'),(52,'MALDONADO HERNANDEZ JUAN RAFAEL','Av. Juarez. s/n','554-234-5555'),(53,'MENDEZ CANO ANGEL','Av. Juarez. s/n','554-234-5555'),(54,'MUÑOZ GOMEZ EDUARDO','Av. Juarez. s/n','554-234-5555'),(55,'OBISPO VARGAS SAUL','Av. Juarez. s/n','554-234-5555'),(56,'OLALDE SOTO JOSE CARLOS','Av. Juarez. s/n','554-234-5555'),(57,'PALMA GONZALEZ CARLOS EPHRA-IM','Av. Juarez. s/n','554-234-5555'),(58,'PEÑA LOPEZ DAVID ISSAI','Av. Juarez. s/n','554-234-5555'),(59,'ROJO SALAZAR JESUS NESTOR','Av. Juarez. s/n','554-234-5555'),(60,'SERRANO GARCIA JOSUE MARIO RAMON','Av. Juarez. s/n','554-234-5555'),(61,'VALENTIN LECHUGA EDDY','Av. Juarez. s/n','554-234-5555'),(62,'VAZQUEZ LAZCANO OSWALDO GIOVANI','Av. Juarez. s/n','554-234-5555'),(63,'VELAZQUEZ TORRES JAVIER JESUS','Av. Juarez. s/n','554-234-5555');
/*!40000 ALTER TABLE `socio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sociosams`
--

DROP TABLE IF EXISTS `sociosams`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `sociosams` (
  `idSocio` int(10) unsigned NOT NULL,
  `idClub` int(10) unsigned NOT NULL,
  PRIMARY KEY (`idSocio`,`idClub`),
  KEY `FK_sociosams_1` (`idClub`),
  CONSTRAINT `FK_sociosams_1` FOREIGN KEY (`idClub`) REFERENCES `club` (`idClub`),
  CONSTRAINT `FK_sociosams_2` FOREIGN KEY (`idSocio`) REFERENCES `socio` (`idSocio`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `sociosams`
--

LOCK TABLES `sociosams` WRITE;
/*!40000 ALTER TABLE `sociosams` DISABLE KEYS */;
INSERT INTO `sociosams` VALUES (1,103),(10,103),(19,103),(28,103),(32,103),(41,103),(50,103),(59,103),(2,104),(11,104),(20,104),(29,104),(33,104),(42,104),(51,104),(60,104),(3,105),(12,105),(21,105),(30,105),(34,105),(43,105),(52,105),(61,105),(5,106),(14,106),(23,106),(35,106),(44,106),(53,106),(62,106),(4,108),(13,108),(22,108),(31,108),(36,108),(45,108),(54,108),(63,108),(6,120),(15,120),(24,120),(37,120),(46,120),(55,120),(7,143),(16,143),(25,143),(38,143),(47,143),(56,143),(8,157),(17,157),(26,157),(39,157),(48,157),(57,157),(9,176),(18,176),(27,176),(40,176),(49,176),(58,176);
/*!40000 ALTER TABLE `sociosams` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-03-22  1:17:49
