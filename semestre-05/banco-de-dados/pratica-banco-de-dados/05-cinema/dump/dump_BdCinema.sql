/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19-11.8.6-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: 127.0.0.1    Database: BdCinema
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
-- Table structure for table `Filmes`
--

DROP TABLE IF EXISTS `Filmes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Filmes` (
  `codf` int(11) NOT NULL,
  `titulo` varchar(50) NOT NULL,
  `duracao` smallint(6) DEFAULT NULL,
  `genero` char(20) DEFAULT NULL,
  PRIMARY KEY (`codf`),
  UNIQUE KEY `uq_filmes_titulo` (`titulo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Filmes`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Filmes` WRITE;
/*!40000 ALTER TABLE `Filmes` DISABLE KEYS */;
/*!40000 ALTER TABLE `Filmes` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Funcionarios`
--

DROP TABLE IF EXISTS `Funcionarios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Funcionarios` (
  `codfu` int(11) NOT NULL,
  `nome` varchar(40) NOT NULL,
  `cargo` varchar(20) DEFAULT NULL,
  `nros` int(11) DEFAULT NULL,
  PRIMARY KEY (`codfu`),
  KEY `fk_funcionarios_salas` (`nros`),
  CONSTRAINT `fk_funcionarios_salas` FOREIGN KEY (`nros`) REFERENCES `Salas` (`nros`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Funcionarios`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Funcionarios` WRITE;
/*!40000 ALTER TABLE `Funcionarios` DISABLE KEYS */;
/*!40000 ALTER TABLE `Funcionarios` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Ingressos`
--

DROP TABLE IF EXISTS `Ingressos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Ingressos` (
  `coding` int(11) NOT NULL,
  `cods` int(11) DEFAULT NULL,
  `CPF` decimal(11,0) DEFAULT NULL,
  `tipo` char(10) DEFAULT NULL,
  `valor` decimal(6,2) DEFAULT NULL,
  `poltrona` varchar(4) DEFAULT NULL,
  PRIMARY KEY (`coding`),
  KEY `fk_ingressos_sessoes` (`cods`),
  CONSTRAINT `fk_ingressos_sessoes` FOREIGN KEY (`cods`) REFERENCES `Sessoes` (`cods`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Ingressos`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Ingressos` WRITE;
/*!40000 ALTER TABLE `Ingressos` DISABLE KEYS */;
/*!40000 ALTER TABLE `Ingressos` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Salas`
--

DROP TABLE IF EXISTS `Salas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Salas` (
  `nros` int(11) NOT NULL,
  `capacidade` smallint(6) NOT NULL,
  PRIMARY KEY (`nros`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Salas`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Salas` WRITE;
/*!40000 ALTER TABLE `Salas` DISABLE KEYS */;
/*!40000 ALTER TABLE `Salas` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Sessoes`
--

DROP TABLE IF EXISTS `Sessoes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Sessoes` (
  `cods` int(11) NOT NULL,
  `codf` int(11) DEFAULT NULL,
  `nros` int(11) DEFAULT NULL,
  `data` date NOT NULL,
  `hora` time NOT NULL,
  `preco` decimal(6,2) NOT NULL,
  PRIMARY KEY (`cods`),
  KEY `fk_sessoes_filmes` (`codf`),
  KEY `fk_sessoes_salas` (`nros`),
  CONSTRAINT `fk_sessoes_filmes` FOREIGN KEY (`codf`) REFERENCES `Filmes` (`codf`),
  CONSTRAINT `fk_sessoes_salas` FOREIGN KEY (`nros`) REFERENCES `Salas` (`nros`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Sessoes`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Sessoes` WRITE;
/*!40000 ALTER TABLE `Sessoes` DISABLE KEYS */;
/*!40000 ALTER TABLE `Sessoes` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Dumping routines for database 'BdCinema'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

-- Dump completed on 2026-11-01 14:02:00
