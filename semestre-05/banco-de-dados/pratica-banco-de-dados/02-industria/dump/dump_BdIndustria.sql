/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19-11.8.6-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: 127.0.0.1    Database: BdIndustria
-- ------------------------------------------------------
-- Server version	11.8.6-MariaDB-0+deb13u1 from Debian

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*M!100616 SET @OLD_NOTE_VERBOSITY=@@NOTE_VERBOSITY, NOTE_VERBOSITY=0 */;

--
-- Table structure for table `Linhas`
--

DROP TABLE IF EXISTS `Linhas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Linhas` (
  `codl` int(11) NOT NULL,
  `nome` varchar(30) NOT NULL,
  PRIMARY KEY (`codl`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Linhas`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Linhas` WRITE;
/*!40000 ALTER TABLE `Linhas` DISABLE KEYS */;
/*!40000 ALTER TABLE `Linhas` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Maquinas`
--

DROP TABLE IF EXISTS `Maquinas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Maquinas` (
  `codm` int(11) NOT NULL,
  `modelo` varchar(30) NOT NULL,
  `ano` smallint(6) DEFAULT NULL,
  `codl` int(11) DEFAULT NULL,
  PRIMARY KEY (`codm`),
  UNIQUE KEY `uq_maquinas_modelo_ano` (`modelo`,`ano`),
  KEY `fk_maquinas_linhas` (`codl`),
  CONSTRAINT `fk_maquinas_linhas` FOREIGN KEY (`codl`) REFERENCES `Linhas` (`codl`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Maquinas`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Maquinas` WRITE;
/*!40000 ALTER TABLE `Maquinas` DISABLE KEYS */;
/*!40000 ALTER TABLE `Maquinas` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Operadores`
--

DROP TABLE IF EXISTS `Operadores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Operadores` (
  `matricula` int(11) NOT NULL,
  `nome` varchar(40) NOT NULL,
  `turno` char(1) NOT NULL,
  `codl` int(11) DEFAULT NULL,
  PRIMARY KEY (`matricula`),
  KEY `fk_operadores_linhas` (`codl`),
  CONSTRAINT `fk_operadores_linhas` FOREIGN KEY (`codl`) REFERENCES `Linhas` (`codl`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Operadores`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Operadores` WRITE;
/*!40000 ALTER TABLE `Operadores` DISABLE KEYS */;
/*!40000 ALTER TABLE `Operadores` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `OrdensProducao`
--

DROP TABLE IF EXISTS `OrdensProducao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `OrdensProducao` (
  `nro` int(11) NOT NULL,
  `codl` int(11) DEFAULT NULL,
  `matricula` int(11) DEFAULT NULL,
  `codm` int(11) DEFAULT NULL,
  `qtd` decimal(10,2) NOT NULL,
  `dt_inicio` date NOT NULL,
  `status` char(12) DEFAULT NULL,
  PRIMARY KEY (`nro`),
  KEY `fk_ordensproducao_linhas` (`codl`),
  KEY `fk_ordensproducao_operadores` (`matricula`),
  KEY `fk_ordensproducao_maquinas` (`codm`),
  CONSTRAINT `fk_ordensproducao_linhas` FOREIGN KEY (`codl`) REFERENCES `Linhas` (`codl`),
  CONSTRAINT `fk_ordensproducao_maquinas` FOREIGN KEY (`codm`) REFERENCES `Maquinas` (`codm`),
  CONSTRAINT `fk_ordensproducao_operadores` FOREIGN KEY (`matricula`) REFERENCES `Operadores` (`matricula`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `OrdensProducao`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `OrdensProducao` WRITE;
/*!40000 ALTER TABLE `OrdensProducao` DISABLE KEYS */;
/*!40000 ALTER TABLE `OrdensProducao` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Dumping routines for database 'BdIndustria'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

-- Dump completed on 2026-11-01 13:36:43
