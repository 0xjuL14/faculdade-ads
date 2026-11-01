/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19-11.8.6-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: 127.0.0.1    Database: BdEscola
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
-- Table structure for table `Alunos`
--

DROP TABLE IF EXISTS `Alunos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Alunos` (
  `ra` int(11) NOT NULL,
  `nome` varchar(40) NOT NULL,
  `idade` smallint(6) NOT NULL,
  `CPF` decimal(11,0) DEFAULT NULL,
  `codc` int(11) DEFAULT NULL,
  PRIMARY KEY (`ra`),
  UNIQUE KEY `uq_alunos_cpf` (`CPF`),
  KEY `fk_alunos_cursos` (`codc`),
  CONSTRAINT `fk_alunos_cursos` FOREIGN KEY (`codc`) REFERENCES `Cursos` (`codc`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Alunos`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Alunos` WRITE;
/*!40000 ALTER TABLE `Alunos` DISABLE KEYS */;
/*!40000 ALTER TABLE `Alunos` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Cursos`
--

DROP TABLE IF EXISTS `Cursos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Cursos` (
  `codc` int(11) NOT NULL,
  `nome` varchar(40) NOT NULL,
  `carga_horaria` smallint(6) DEFAULT NULL,
  PRIMARY KEY (`codc`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Cursos`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Cursos` WRITE;
/*!40000 ALTER TABLE `Cursos` DISABLE KEYS */;
/*!40000 ALTER TABLE `Cursos` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Matriculas`
--

DROP TABLE IF EXISTS `Matriculas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Matriculas` (
  `ra` int(11) NOT NULL,
  `codt` int(11) NOT NULL,
  `nota` decimal(4,2) DEFAULT NULL,
  `faltas` smallint(6) DEFAULT NULL,
  `status` char(10) DEFAULT NULL,
  PRIMARY KEY (`ra`,`codt`),
  KEY `fk_matriculas_turmas` (`codt`),
  CONSTRAINT `fk_matriculas_alunos` FOREIGN KEY (`ra`) REFERENCES `Alunos` (`ra`),
  CONSTRAINT `fk_matriculas_turmas` FOREIGN KEY (`codt`) REFERENCES `Turmas` (`codt`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Matriculas`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Matriculas` WRITE;
/*!40000 ALTER TABLE `Matriculas` DISABLE KEYS */;
/*!40000 ALTER TABLE `Matriculas` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Professores`
--

DROP TABLE IF EXISTS `Professores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Professores` (
  `codpr` int(11) NOT NULL,
  `nome` varchar(40) NOT NULL,
  `titulacao` char(15) DEFAULT NULL,
  `CPF` decimal(11,0) DEFAULT NULL,
  PRIMARY KEY (`codpr`),
  UNIQUE KEY `uq_professores_cpf` (`CPF`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Professores`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Professores` WRITE;
/*!40000 ALTER TABLE `Professores` DISABLE KEYS */;
/*!40000 ALTER TABLE `Professores` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Table structure for table `Turmas`
--

DROP TABLE IF EXISTS `Turmas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Turmas` (
  `codt` int(11) NOT NULL,
  `codc` int(11) DEFAULT NULL,
  `codpr` int(11) DEFAULT NULL,
  `semestre` char(6) NOT NULL,
  PRIMARY KEY (`codt`),
  KEY `fk_turmas_cursos` (`codc`),
  KEY `fk_turmas_professores` (`codpr`),
  CONSTRAINT `fk_turmas_cursos` FOREIGN KEY (`codc`) REFERENCES `Cursos` (`codc`),
  CONSTRAINT `fk_turmas_professores` FOREIGN KEY (`codpr`) REFERENCES `Professores` (`codpr`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Turmas`
--

SET @OLD_AUTOCOMMIT=@@AUTOCOMMIT, @@AUTOCOMMIT=0;
LOCK TABLES `Turmas` WRITE;
/*!40000 ALTER TABLE `Turmas` DISABLE KEYS */;
/*!40000 ALTER TABLE `Turmas` ENABLE KEYS */;
UNLOCK TABLES;
COMMIT;
SET AUTOCOMMIT=@OLD_AUTOCOMMIT;

--
-- Dumping routines for database 'BdEscola'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

-- Dump completed on 2026-11-01 13:53:10
