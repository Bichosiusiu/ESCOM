DROP DATABASE singularityU;
CREATE DATABASE singularityU;
USE singularityU;
CREATE TABLE Universidad
(
  idUniversidad INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  nombre VARCHAR(70) DEFAULT NULL
);

CREATE TABLE AliadoReg (
        IdAliado INT UNSIGNED,
        nombre VARCHAR(20),
        fechaCambio DATETIME
    );


CREATE TABLE Aliados
(
  IdAliado INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  nombre VARCHAR(20) DEFAULT NULL
);

CREATE TABLE Areas
(
  IdArea  VARCHAR(3) NOT NULL PRIMARY KEY,
  nombre VARCHAR(50) DEFAULT NULL
);

CREATE TABLE Evento
(
  IdEvento INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  nombre VARCHAR(70) DEFAULT NULL,
  edicion INT DEFAULT NULL,
  ubicacion VARCHAR(30) DEFAULT NULL,
  idUniversidad INT UNSIGNED NOT NULL,
  FOREIGN KEY (idUniversidad) REFERENCES Universidad(idUniversidad) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Articulos
(
  IdArticulos INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  titulo VARCHAR(100) DEFAULT NULL,
  idioma VARCHAR(30) DEFAULT NULL,
  resumen VARCHAR(200) DEFAULT NULL,
  idUniversidad INT UNSIGNED NOT NULL,
  FOREIGN KEY (idUniversidad) REFERENCES Universidad(idUniversidad) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Clientes
(
  IdAliado INT UNSIGNED NOT NULL,
  idUniversidad INT UNSIGNED NOT NULL,
  PRIMARY KEY (IdAliado,idUniversidad),
  FOREIGN KEY (IdAliado) REFERENCES Aliados(IdAliado) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (idUniversidad) REFERENCES Universidad(idUniversidad) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Universidad_pais
(
  pais VARCHAR(20) NOT NULL,
  idUniversidad INT UNSIGNED NOT NULL,
  PRIMARY KEY (pais,idUniversidad),
  FOREIGN KEY (idUniversidad) REFERENCES Universidad(idUniversidad) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Ponentes
(
  IdPonente INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  nombre VARCHAR(30) DEFAULT NULL,
  Educacion VARCHAR(30) DEFAULT NULL,
  IdArea VARCHAR(3) NOT NULL,
  FOREIGN KEY (IdArea) REFERENCES Areas(IdArea) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE ponenteUni
(
  idUniversidad INT UNSIGNED NOT NULL,
  IdPonente INT UNSIGNED NOT NULL,
  PRIMARY KEY (idUniversidad,IdPonente),
  FOREIGN KEY (idUniversidad) REFERENCES Universidad(idUniversidad)ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (IdPonente) REFERENCES Ponentes(IdPonente)ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE participacionPonente (
    IdPonente INT UNSIGNED NOT NULL,
    IdEvento INT UNSIGNED NOT NULL,
    PRIMARY KEY (IdPonente,IdEvento),
    FOREIGN KEY (IdPonente) REFERENCES Ponentes (IdPonente) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (IdEvento) REFERENCES Evento (IdEvento) ON DELETE CASCADE ON UPDATE CASCADE
);
insert into Universidad (nombre) values ("Singularity University Mexico");
insert into Universidad (nombre) values ("Singularity University Colombia");
insert into Universidad (nombre) values ("Singularity University Madrid");
insert into Universidad (nombre) values ("Singularity University Nordic");
insert into Universidad (nombre) values ("Singularity University Netherlands");
insert into Universidad (nombre) values ("Singularity University USA");
insert into Universidad (nombre) values ("Singularity University India");
insert into Universidad (nombre) values ("Singularity University Italia");
insert into Universidad (nombre) values ("Singularity University Portugal");
insert into Universidad (nombre) values ("Singularity University Argentina");
insert into Universidad (nombre) values ("Singularity University Chile");
insert into Universidad (nombre) values ("Singularity University Brasil");
insert into Aliados (nombre) values ("Deloite");
insert into Aliados (nombre) values ("Expansion");
insert into Aliados (nombre) values ("Arbomex");
insert into Aliados (nombre) values ("Rockspace");
insert into Aliados (nombre) values ("Terra");
insert into Aliados (nombre) values ("Tresalia");
insert into Aliados (nombre) values ("B");
insert into Aliados (nombre) values ("Bayer");
insert into Aliados (nombre) values ("GNP");
insert into Aliados (nombre) values ("Coursera");
insert into Aliados (nombre) values ("Oracle");
insert into Aliados (nombre) values ("GBM");
insert into Aliados (nombre) values ("Nestle");
insert into Aliados (nombre) values ("Fortinet");
insert into Aliados (nombre) values ("Televisa");
insert into Aliados (nombre) values ("Santander");
insert into Aliados (nombre) values ("Pepsico");
insert into Aliados (nombre) values ("Coca Cola");
insert into Aliados (nombre) values ("Profuturo");
insert into Aliados (nombre) values ("Speakology");
insert into Aliados (nombre) values ("Banorte");
insert into Aliados (nombre) values ("Rappi");
insert into Aliados (nombre) values ("Redbox");
insert into Aliados (nombre) values ("wework");
insert into Aliados (nombre) values ("Haworth");
insert into Aliados (nombre) values ("Zarpo");
insert into Aliados (nombre) values ("Casa Dragones");
insert into Aliados (nombre) values ("Alchemy labs");
insert into Aliados (nombre) values ("Tec Monterrey");
insert into Aliados (nombre) values ("Cinepolis");
insert into Areas values ("FDR","Futuro de Retail");
insert into Areas values ("EXP","Exponencialidad");
insert into Areas values ("IA","Inteligencia Artificial");
insert into Areas values ("PEX","Penamiento Exponencial");
insert into Areas values ("CSR","Ciberseguridad");
insert into Areas values ("MEX","Mentalidad Exponencial");
insert into Areas values ("EMP","Emprendimiento");
insert into Areas values ("FDE","Futuro de la Educacion");
insert into Areas values ("NEU","Neurociencia");
insert into Areas values ("CDF","Ciencia de la Felicidad");
insert into Areas values ("SM","Salud Mental");
insert into Areas values ("IGN","Ingenieria Genetica");
insert into Areas values ("MED","Medicina");
insert into Areas values ("INN","Innovacion");
insert into Areas values ("CDR","Crecimiento Disruptivo");
insert into Areas values ("FUT","Futuro");
insert into Areas values ("FDT","Futuro del Trabajo");
insert into Areas values ("FDC","Futuro de la comida");
insert into Areas values ("ROB","Robotica");
insert into Areas values ("ARQ","Arquitectura");
insert into Areas values ("LON","Longevidad");
insert into Areas values ("ENG","Energia");
insert into Areas values ("PH","Potencial Humano");
insert into Areas values ("TEC","Tecnologia");
insert into Areas values ("LID","Liderazgo");
insert into Areas values ("BIG","BIG DATA");
insert into Areas values ("BIO","Biotecnologia");
insert into Areas values ("RET","Retail");
insert into Areas values ("DIG","Fluidez Digital");
insert into Areas values ("CRY","Crypto");
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Mexico Summit Jalisco",2019,"Jalisco",1);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit Jalisco",2020,"Jalisco",1);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Mexico Summit Jalisco",2018,"Jalisco",1);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Jalisco",2021,"Jalisco",1);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Jalisco",2017,"Jalisco",1);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Bogota",2023,"Bogota",2);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit Madrid",2020,"Madrid",3);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU España Summit Barcelona",2023,"Barcelona",3);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Denmark",2022,"Copenhague",4);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit Netherlands",2020,"Amsterdam",5);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU USA-Canada Summit Alaska",2023,"Alaska",6);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series LA",2022,"Los Angeles",6);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit India-China",2023,"Hong Kong",7);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU India-China Summit India",2023,"Nueva Delhi",7);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Benecia",2019,"Benecia",8);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit Turin",2018,"Turin",8);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Italia Summit Roma",2022,"Roma",8);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Milan",2021,"Milan",8);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit Portugal",2022,"Lisboa",9);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Portugal Summit Aveiro",2023,"Aveiro",9);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Oporto",2021,"Oporto",9);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit Argentina",2021,"Buenoas Aires",10);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Argentina-Uruguay Summit La Plata",2022,"La Plata",10);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Montevideo",2020,"Montevideo",10);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit Chile-Peru",2020,"Santiago",11);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Chile-Peru Summit Lima",2021,"Lima",11);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Puerto Varas",2022,"Puerto Varas",11);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Virtual Summit Brasil",2020,"Rio de Janeiro",12);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Brasil-Bolivia Summit La Paz",2023,"La Paz",12);
insert into Evento(nombre, edicion, ubicacion,idUniversidad) values("SingularityU Digital Series Brasilia",2022,"Brasilia",12);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("4 tips para potenciar la colaboración humano + máquina en tu empresa","Español","Cuál es el primer pensamiento que viene a tu mente cuando escuchas Inteligencia Artificial? Seguramente robots realizando tareas que antes hacían los humanos.",1);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("Computación Cuántica, la Revolución Tecnológica que cambiará el mundo","Español","En 2019, IBM presentó el primer ordenador cuántico comercial del mundo. Bautizado como IBM Q System One, este ordenador no tiene pantallas, teclados o procesadores.",1);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("Automatización, la clave de una empresa productiva","Español","Con el avance tecnológico, los modelos empresariales se van transformando, por lo que se requieren mejores procesos de automatización, ¿pero qué significa eso?",1);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("¿Es posible revertir el envejecimiento?","Español","Hace 200 años parecía imposible, pero en la actualidad las investigaciones científicas destinan más tiempo y recursos a la biotecnología para conseguir un objetivo: que los humanos vivan eternamente.",2);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("3 empresas que domesticaron Big Data a la perfección","Español","Vivimos en un momento en el que las organizaciones de todo el mundo tienen big data aplicada de distintas formas  y tamaños.",3);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("Fintech es el futuro de la economía","Español","Con la reciente pandemia global que vivimos nos hemos visto presionados a innovar en distintas formas, principalmente formas que eviten la cercanía o el contacto",3);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("AI-Powered Brain Implant Smashes Speed Record for Turning Thoughts Into Text","Ingles","We speak at a rate of roughly 160 words every minute. That speed is incredibly difficult to achieve for speech brain implants.",4);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("Scientists Merge Biology and Technology by 3D Printing Electronics Inside Living Worms","Ingles","Finding ways to integrate electronics into living tissue could be crucial for everything from brain implants to new medical technologies.",4);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("AI Won’t Kill Our Jobs, It Will Kill Our Job Descriptions—and Leave Us Better Off","Ingles","The hype around artificial intelligence has been building for years, and you could say it reached a crescendo with OpenAI’s recent release of ChatGPT (and now GPT-4).",5);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("This Chipmaking Step Is Crucial to the Future of Computing—and Just Got 40x Faster Thanks to Nvidia","Ingles","If computer chips make the modern world go around, then Nvidia and TSMC are flywheels keeping it spinning. It’s worth paying attention when the former says they’ve made a chipmaking breakthrough",5);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("ChatGPT Is Great—You’re Just Using It Wrong","Ingles","It doesn’t take much to get ChatGPT to make a factual mistake. My son is doing a report on US presidents, so I figured I’d help him out by looking up a few biographies.",6);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("This Week’s Awesome Tech Stories From Around the Web (Through September 24)","Ingles","“The competition to create ever smaller, ever better robots is a fierce one, and Cornell University is out front now with a set of bots small enough to sit on a human hair ”",6);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("Scientists Engineer Bacteria to Recycle Plastic Waste Into Valuable Chemicals","Ingles","Plastic waste is clogging up our rivers and oceans and causing long-lasting environmental damage that is only just starting to come into focus",6);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("This Exoskeleton Uses AI to Help People Walk Faster With Less Energy","Ingles","Exoskeletons have been largely confined to the realm of fiction, appearing in sci-fi or superhero movies to make characters stronger, taller, or more destructive",7);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("800,000 Neurons in a Dish Learned to Play Pong in Just Five Minutes","Ingles","Scientists just taught hundreds of thousands of neurons in a dish to play Pong. Using a series of strategically timed and placed electrical zaps",7);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("This Week’s Awesome Tech Stories From Around the Web (Through August 6)","Ingles","“The real novelty with Synchron’s device, he says, is that surgeons don’t have to cut open your brain, making it far less invasive, and therefore less risky for patients",8);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("There Are Cheaper, More Sustainable Ways Than Desalination to Meet Our Water Needs","Ingles","Coastal urban centers around the world are urgently looking for new, sustainable water sources as their local supplies become less reliable.",8);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("The Tech That Will Push VR to the Limits of the Human Eye","Ingles","Big tech is eager to get us excited about the coming of the metaverse, but today’s virtual reality hardware is a long way from meeting their ambitious goals.",9);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("A Massive Carbon Capture Plant in Wyoming Will Pull 5 Million Tons of CO2 From the Air Each Year","Ingles","Though it’s still a controversial technology, direct air capture—also called carbon capture—is gaining traction. In the last few years",9);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("OpenAI Says DALL-E Is Generating Over 2 Million Images a Day—and That’s Just Table Stakes","Ingles","The venerable stock image site, Getty, boasts a catalog of 80 million images. Shutterstock, a rival of Getty, offers 415 million images",9);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("El liderazgo después de la pandemia","Español","Desde que la pandemia de Covid-19 apareció, la respuesta principal de muchas empresas se ha centrado en proteger a su personal, proteger a la empresa y mantenerse a flote.",10);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("Biofeedback y Neurofeedback, los nuevos jugadores contra el estrés","Español","El uso de la tecnología para el bienestar psicológico ha crecido exponencialmente en los últimos años, usamos el Internet como un puente para impartir psicoeducacion",10);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("La inteligencia Artificial como herramienta contra el Parkinson","Español","Lo más probable es que sepas que el actor Michael J. Fox vive con la enfermedad de Parkinson. En el año 2000, Fox lanzó su propia fundación para la Investigación del Parkinson (MJFF)",10);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("Olvidar para mejorar, así es el unlearning empresarial","Español","Existen muchos expertos que consideran que las habilidades y capacidades distintivas de las empresas se agrupan en tres categorías",10);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("¿Cómo será el trabajo después del COVID?","Español","La pandemia de COVID-19 ha representado uno de los retos más grandes a los que se ha enfrentado el mundo, además de afectar a la salud física y emocional de millones de personas",11);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("3 Empresas que han usado el Internet de las cosas a su favor. ¿Tu empresa será la cuarta?","Español","El Internet de las cosas es un tema que poco a poco ha cobrado mayor relevancia técnica, social y económica.",11);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("3 Medidas de ciberseguridad para blindar tu empresa","Español","Crear una presencia digital sólida otorga a las empresas importantes ventajas competitivas como: interacción con el cliente en tiempo real, nuevas ventas, canales y comunicación dirigida",11);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("This Week’s Awesome Tech Stories From Around the Web (Through July 30)","Ingles","From today, the Alphabet-owned AI lab is offering its database of over 200 million proteins to anyone for free. …The update includes structures for ‘plants, bacteria, animals, and many",12);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("Quantum Computers Could Crack Bitcoin. Here’s What It Would Take","Ingles","Quantum computers could cause unprecedented disruption in both good and bad ways, from cracking the encryption that secures our data to solving some of chemistry’s most intractable puzzles",12);
insert into Articulos(titulo,idioma,resumen,idUniversidad) values("La IA en nuestro entorno","Español","Como afectara la IA en nuestro entorno tanto laboral como economico , una breve introduccion al nuevo orden del mañana tomando en cuenta el avance tecnologico",12);
insert into Clientes(IdAliado,idUniversidad) values(1,1);
insert into Clientes(IdAliado,idUniversidad) values(1,2);
insert into Clientes(IdAliado,idUniversidad) values(2,2);
insert into Clientes(IdAliado,idUniversidad) values(2,3);
insert into Clientes(IdAliado,idUniversidad) values(2,4);
insert into Clientes(IdAliado,idUniversidad) values(3,5);
insert into Clientes(IdAliado,idUniversidad) values(4,5);
insert into Clientes(IdAliado,idUniversidad) values(5,5);
insert into Clientes(IdAliado,idUniversidad) values(6,6);
insert into Clientes(IdAliado,idUniversidad) values(6,7);
insert into Clientes(IdAliado,idUniversidad) values(7,8);
insert into Clientes(IdAliado,idUniversidad) values(7,9);
insert into Clientes(IdAliado,idUniversidad) values(8,10);
insert into Clientes(IdAliado,idUniversidad) values(9,10);
insert into Clientes(IdAliado,idUniversidad) values(9,11);
insert into Clientes(IdAliado,idUniversidad) values(10,12);
insert into Clientes(IdAliado,idUniversidad) values(10,11);
insert into Clientes(IdAliado,idUniversidad) values(11,11);
insert into Clientes(IdAliado,idUniversidad) values(12,11);
insert into Clientes(IdAliado,idUniversidad) values(13,10);
insert into Clientes(IdAliado,idUniversidad) values(13,9);
insert into Clientes(IdAliado,idUniversidad) values(14,9);
insert into Clientes(IdAliado,idUniversidad) values(14,8);
insert into Clientes(IdAliado,idUniversidad) values(15,8);
insert into Clientes(IdAliado,idUniversidad) values(16,7);
insert into Clientes(IdAliado,idUniversidad) values(17,7);
insert into Clientes(IdAliado,idUniversidad) values(18,6);
insert into Clientes(IdAliado,idUniversidad) values(19,6);
insert into Clientes(IdAliado,idUniversidad) values(20,5);
insert into Clientes(IdAliado,idUniversidad) values(20,4);
insert into Clientes(IdAliado,idUniversidad) values(21,3);
insert into Clientes(IdAliado,idUniversidad) values(22,3);
insert into Clientes(IdAliado,idUniversidad) values(22,2);
insert into Clientes(IdAliado,idUniversidad) values(23,1);
insert into Clientes(IdAliado,idUniversidad) values(24,1);
insert into Clientes(IdAliado,idUniversidad) values(25,2);
insert into Clientes(IdAliado,idUniversidad) values(25,3);
insert into Clientes(IdAliado,idUniversidad) values(25,4);
insert into Clientes(IdAliado,idUniversidad) values(26,4);
insert into Clientes(IdAliado,idUniversidad) values(27,4);
insert into Clientes(IdAliado,idUniversidad) values(28,5);
insert into Clientes(IdAliado,idUniversidad) values(28,6);
insert into Clientes(IdAliado,idUniversidad) values(29,7);
insert into Clientes(IdAliado,idUniversidad) values(30,8);
insert into Clientes(IdAliado,idUniversidad) values(30,9);
insert into universidad_pais(pais,idUniversidad) values("Mexico",1);
insert into universidad_pais(pais,idUniversidad) values("Colombia",2);
insert into universidad_pais(pais,idUniversidad) values("España",3);
insert into universidad_pais(pais,idUniversidad) values("Francia",3);
insert into universidad_pais(pais,idUniversidad) values("Dinamarca",4);
insert into universidad_pais(pais,idUniversidad) values("Finlandia",4);
insert into universidad_pais(pais,idUniversidad) values("Suecia",4);
insert into universidad_pais(pais,idUniversidad) values("Noruega",4);
insert into universidad_pais(pais,idUniversidad) values("Islandia",4);
insert into universidad_pais(pais,idUniversidad) values("Paises Bajos",5);
insert into universidad_pais(pais,idUniversidad) values("USA",6);
insert into universidad_pais(pais,idUniversidad) values("Canada",6);
insert into universidad_pais(pais,idUniversidad) values("India",7);
insert into universidad_pais(pais,idUniversidad) values("China",7);
insert into universidad_pais(pais,idUniversidad) values("Filipinas",7);
insert into universidad_pais(pais,idUniversidad) values("Japon",7);
insert into universidad_pais(pais,idUniversidad) values("Corea del Sur",7);
insert into universidad_pais(pais,idUniversidad) values("Coreal del Norte",7);
insert into universidad_pais(pais,idUniversidad) values("Italia",8);
insert into universidad_pais(pais,idUniversidad) values("Alemania",8);
insert into universidad_pais(pais,idUniversidad) values("Hungria",8);
insert into universidad_pais(pais,idUniversidad) values("Grecias",8);
insert into universidad_pais(pais,idUniversidad) values("Portugal",9);
insert into universidad_pais(pais,idUniversidad) values("Angola",9);
insert into universidad_pais(pais,idUniversidad) values("Marruecos",3);
insert into universidad_pais(pais,idUniversidad) values("Argentina",10);
insert into universidad_pais(pais,idUniversidad) values("Uruguay",10);
insert into universidad_pais(pais,idUniversidad) values("Chile",11);
insert into universidad_pais(pais,idUniversidad) values("Peru",11);
insert into universidad_pais(pais,idUniversidad) values("Brasil",12);
insert into universidad_pais(pais,idUniversidad) values("Bolivia",12);
insert into Ponentes(nombre,Educacion,IdArea) values("Vivian Lan"," Singularity University","EXP");
insert into Ponentes(nombre,Educacion,IdArea) values("Dr. Kai-Fu Lee","Universidad de Columbia","IA");
insert into Ponentes(nombre,Educacion,IdArea) values("Vivienne Ming","Redwood Center","IA");
insert into Ponentes(nombre,Educacion,IdArea) values("Peter Diamandis","MIT","PEX");
insert into Ponentes(nombre,Educacion,IdArea) values("Jaya Baloo","Singularity University","CSR");
insert into Ponentes(nombre,Educacion,IdArea) values("Jason Silva","Singularity University","MEX");
insert into Ponentes(nombre,Educacion,IdArea) values("Anousheh Ansari","Universidad George Mason","EMP");
insert into Ponentes(nombre,Educacion,IdArea) values("Taddy Blecher","Singularity University","FDE");
insert into Ponentes(nombre,Educacion,IdArea) values("Divya Chander","Harvard","NEU");
insert into Ponentes(nombre,Educacion,IdArea) values("Tal Ben Shahar","Harvard","CDF");
insert into Ponentes(nombre,Educacion,IdArea) values("Doug Stephens","St. Mary’s University","FDR");
insert into Ponentes(nombre,Educacion,IdArea) values("Parneet Pal","Harvard","SM");
insert into Ponentes(nombre,Educacion,IdArea) values("Jamie Metzl","Oxford","IGN");
insert into Ponentes(nombre,Educacion,IdArea) values("Alix Rübsaam","Universidad de Ámsterdam","IA");
insert into Ponentes(nombre,Educacion,IdArea) values("Anthony Atala"," Institute of Medicine","MED");
insert into Ponentes(nombre,Educacion,IdArea) values("David Roberts","Singularity University","INN");
insert into Ponentes(nombre,Educacion,IdArea) values("Maurice Conti","Singularity University","FUT");
insert into Ponentes(nombre,Educacion,IdArea) values("Stacey Ferreira","Singulary University","FDT");
insert into Ponentes(nombre,Educacion,IdArea) values("Amin Toufani","Stanford","EXP");
insert into Ponentes(nombre,Educacion,IdArea) values("Pascal Finette","Singulary University","LID");
insert into Ponentes(nombre,Educacion,IdArea) values("Mark Post","Harvard","FDC");
insert into Ponentes(nombre,Educacion,IdArea) values("Daniel Vogel","Stanford","CRY");
insert into Ponentes(nombre,Educacion,IdArea) values("Michel Rojkind","Singulary University","ARQ");
insert into Ponentes(nombre,Educacion,IdArea) values("Tiffany Vora","Universidad de Nueva York","LON");
insert into Ponentes(nombre,Educacion,IdArea) values("Hod Lipson","Universidad de Columbia","ROB");
insert into Ponentes(nombre,Educacion,IdArea) values("Ramsez Naam","Singulary University","ENG");
insert into Ponentes(nombre,Educacion,IdArea) values("Shuo Chen","Singulary University","PH");
insert into Ponentes(nombre,Educacion,IdArea) values("Bismarck Lepe","Singulary University","TEC");
insert into Ponentes(nombre,Educacion,IdArea) values("Ja-Naé Duan","Singulary University","TEc");
insert into Ponentes(nombre,Educacion,IdArea) values("Drew Dudley","Singulary University","LID");
insert into Ponentes(nombre,Educacion,IdArea) values("Tricia Wang","Singulary University","BIG");
insert into Ponentes(nombre,Educacion,IdArea) values("Raymond McCauley","Stanford","BIO");
insert into Ponentes(nombre,Educacion,IdArea) values("Pola Zen","Singulary University","RET");
insert into Ponentes(nombre,Educacion,IdArea) values("MJ Petroni","Lewis & Clark College","DIG");
insert into Ponentes(nombre,Educacion,IdArea) values("Laila Pawlak","Singulary University","LID");
insert into Ponentes(nombre,Educacion,IdArea) values("Charlene Li","Harvard ","CDR");
insert into ponenteuni(idUniversidad,IdPonente) values(1,1);
insert into ponenteuni(idUniversidad,IdPonente) values(1,3);
insert into ponenteuni(idUniversidad,IdPonente) values(2,3);
insert into ponenteuni(idUniversidad,IdPonente) values(2,4);
insert into ponenteuni(idUniversidad,IdPonente) values(3,4);
insert into ponenteuni(idUniversidad,IdPonente) values(3,5);
insert into ponenteuni(idUniversidad,IdPonente) values(4,5);
insert into ponenteuni(idUniversidad,IdPonente) values(5,5);
insert into ponenteuni(idUniversidad,IdPonente) values(5,6);
insert into ponenteuni(idUniversidad,IdPonente) values(5,7);
insert into ponenteuni(idUniversidad,IdPonente) values(6,8);
insert into ponenteuni(idUniversidad,IdPonente) values(6,9);
insert into ponenteuni(idUniversidad,IdPonente) values(7,9);
insert into ponenteuni(idUniversidad,IdPonente) values(7,10);
insert into ponenteuni(idUniversidad,IdPonente) values(8,10);
insert into ponenteuni(idUniversidad,IdPonente) values(9,11);
insert into ponenteuni(idUniversidad,IdPonente) values(9,12);
insert into ponenteuni(idUniversidad,IdPonente) values(9,13);
insert into ponenteuni(idUniversidad,IdPonente) values(10,13);
insert into ponenteuni(idUniversidad,IdPonente) values(10,14);
insert into ponenteuni(idUniversidad,IdPonente) values(11,14);
insert into ponenteuni(idUniversidad,IdPonente) values(11,15);
insert into ponenteuni(idUniversidad,IdPonente) values(11,16);
insert into ponenteuni(idUniversidad,IdPonente) values(12,16);
insert into ponenteuni(idUniversidad,IdPonente) values(12,17);
insert into ponenteuni(idUniversidad,IdPonente) values(12,18);
insert into ponenteuni(idUniversidad,IdPonente) values(11,18);
insert into ponenteuni(idUniversidad,IdPonente) values(11,19);
insert into ponenteuni(idUniversidad,IdPonente) values(11,20);
insert into ponenteuni(idUniversidad,IdPonente) values(10,21);
insert into ponenteuni(idUniversidad,IdPonente) values(10,22);
insert into ponenteuni(idUniversidad,IdPonente) values(9,23);
insert into ponenteuni(idUniversidad,IdPonente) values(9,24);
insert into ponenteuni(idUniversidad,IdPonente) values(8,25);
insert into ponenteuni(idUniversidad,IdPonente) values(7,26);
insert into ponenteuni(idUniversidad,IdPonente) values(6,26);
insert into ponenteuni(idUniversidad,IdPonente) values(5,27);
insert into ponenteuni(idUniversidad,IdPonente) values(5,28);
insert into ponenteuni(idUniversidad,IdPonente) values(4,29);
insert into ponenteuni(idUniversidad,IdPonente) values(3,29);
insert into ponenteuni(idUniversidad,IdPonente) values(3,30);
insert into ponenteuni(idUniversidad,IdPonente) values(2,31);
insert into ponenteuni(idUniversidad,IdPonente) values(2,32);
insert into ponenteuni(idUniversidad,IdPonente) values(1,32);
insert into ponenteuni(idUniversidad,IdPonente) values(1,33);
insert into ponenteuni(idUniversidad,IdPonente) values(2,34);
insert into ponenteuni(idUniversidad,IdPonente) values(2,35);
insert into ponenteuni(idUniversidad,IdPonente) values(3,36);
insert into ponenteuni(idUniversidad,IdPonente) values(3,2);
select * from ponentes;
insert into participacionponente(IdPonente,IdEvento) values(1,1);
insert into participacionponente(IdPonente,IdEvento) values(1,2);
insert into participacionponente(IdPonente,IdEvento) values(3,2);
insert into participacionponente(IdPonente,IdEvento) values(3,3);
insert into participacionponente(IdPonente,IdEvento) values(3,4);
insert into participacionponente(IdPonente,IdEvento) values(4,4);
insert into participacionponente(IdPonente,IdEvento) values(5,4);
insert into participacionponente(IdPonente,IdEvento) values(5,5);
insert into participacionponente(IdPonente,IdEvento) values(5,6);
insert into participacionponente(IdPonente,IdEvento) values(6,6);
insert into participacionponente(IdPonente,IdEvento) values(6,7);
insert into participacionponente(IdPonente,IdEvento) values(6,8);
insert into participacionponente(IdPonente,IdEvento) values(6,9);
insert into participacionponente(IdPonente,IdEvento) values(6,10);
insert into participacionponente(IdPonente,IdEvento) values(7,11);
insert into participacionponente(IdPonente,IdEvento) values(7,12);
insert into participacionponente(IdPonente,IdEvento) values(7,13);
insert into participacionponente(IdPonente,IdEvento) values(8,14);
insert into participacionponente(IdPonente,IdEvento) values(8,15);
insert into participacionponente(IdPonente,IdEvento) values(9,15);
insert into participacionponente(IdPonente,IdEvento) values(10,16);
insert into participacionponente(IdPonente,IdEvento) values(10,17);
insert into participacionponente(IdPonente,IdEvento) values(10,18);
insert into participacionponente(IdPonente,IdEvento) values(10,19);
insert into participacionponente(IdPonente,IdEvento) values(11,20);
insert into participacionponente(IdPonente,IdEvento) values(11,21);
insert into participacionponente(IdPonente,IdEvento) values(11,22);
insert into participacionponente(IdPonente,IdEvento) values(11,23);
insert into participacionponente(IdPonente,IdEvento) values(12,23);
insert into participacionponente(IdPonente,IdEvento) values(12,24);
insert into participacionponente(IdPonente,IdEvento) values(12,25);
insert into participacionponente(IdPonente,IdEvento) values(13,26);
insert into participacionponente(IdPonente,IdEvento) values(13,27);
insert into participacionponente(IdPonente,IdEvento) values(14,27);
insert into participacionponente(IdPonente,IdEvento) values(14,28);
insert into participacionponente(IdPonente,IdEvento) values(14,29);
insert into participacionponente(IdPonente,IdEvento) values(15,30);
insert into participacionponente(IdPonente,IdEvento) values(15,29);
insert into participacionponente(IdPonente,IdEvento) values(15,28);
insert into participacionponente(IdPonente,IdEvento) values(15,27);
insert into participacionponente(IdPonente,IdEvento) values(16,26);
insert into participacionponente(IdPonente,IdEvento) values(16,25);
insert into participacionponente(IdPonente,IdEvento) values(16,24);
insert into participacionponente(IdPonente,IdEvento) values(16,23);
insert into participacionponente(IdPonente,IdEvento) values(17,22);
insert into participacionponente(IdPonente,IdEvento) values(18,21);
insert into participacionponente(IdPonente,IdEvento) values(18,20);
insert into participacionponente(IdPonente,IdEvento) values(18,19);
insert into participacionponente(IdPonente,IdEvento) values(19,18);
insert into participacionponente(IdPonente,IdEvento) values(19,17);
insert into participacionponente(IdPonente,IdEvento) values(20,16);
insert into participacionponente(IdPonente,IdEvento) values(20,15);
insert into participacionponente(IdPonente,IdEvento) values(20,14);
insert into participacionponente(IdPonente,IdEvento) values(21,13);
insert into participacionponente(IdPonente,IdEvento) values(21,12);
insert into participacionponente(IdPonente,IdEvento) values(22,11);
insert into participacionponente(IdPonente,IdEvento) values(22,10);
insert into participacionponente(IdPonente,IdEvento) values(22,9);
insert into participacionponente(IdPonente,IdEvento) values(23,8);
insert into participacionponente(IdPonente,IdEvento) values(23,7);
insert into participacionponente(IdPonente,IdEvento) values(23,6);
insert into participacionponente(IdPonente,IdEvento) values(24,5);
insert into participacionponente(IdPonente,IdEvento) values(24,4);
insert into participacionponente(IdPonente,IdEvento) values(25,3);
insert into participacionponente(IdPonente,IdEvento) values(25,2);
insert into participacionponente(IdPonente,IdEvento) values(25,1);
insert into participacionponente(IdPonente,IdEvento) values(26,1);
insert into participacionponente(IdPonente,IdEvento) values(26,2);
insert into participacionponente(IdPonente,IdEvento) values(26,3);
insert into participacionponente(IdPonente,IdEvento) values(27,4);
insert into participacionponente(IdPonente,IdEvento) values(27,5);
insert into participacionponente(IdPonente,IdEvento) values(28,6);
insert into participacionponente(IdPonente,IdEvento) values(29,7);
insert into participacionponente(IdPonente,IdEvento) values(30,8);
insert into participacionponente(IdPonente,IdEvento) values(30,9);
insert into participacionponente(IdPonente,IdEvento) values(31,10);
insert into participacionponente(IdPonente,IdEvento) values(32,11);
insert into participacionponente(IdPonente,IdEvento) values(33,12);
insert into participacionponente(IdPonente,IdEvento) values(33,13);
insert into participacionponente(IdPonente,IdEvento) values(34,14);
insert into participacionponente(IdPonente,IdEvento) values(35,15);
insert into participacionponente(IdPonente,IdEvento) values(35,16);
insert into participacionponente(IdPonente,IdEvento) values(36,17);
insert into participacionponente(IdPonente,IdEvento) values(36,18);
insert into participacionponente(IdPonente,IdEvento) values(2,19);
show tables;

SELECT * FROM aliados;

SELECT * FROM  areas;

SELECT * FROM  articulos;

SELECT * FROM  clientes;

SELECT * FROM  evento;

SELECT * FROM  participacionponente;

SELECT * FROM  ponentes;

SELECT * FROM  ponenteuni;

SELECT * FROM  universidad;

SELECT * FROM  universidad_pais;



-- VISTAS
CREATE VIEW vista1 AS
	SELECT p.nombre AS "PONENTE", u.nombre AS "UNIVERSIDAD", a.nombre AS "AREA"
    FROM areas a INNER JOIN ponentes p ON a.IdArea = p.IdArea
    INNER JOIN ponenteuni pu ON p.IdPonente = pu.IdPonente
    INNER JOIN universidad u ON u.idUniversidad = pu.idUniversidad
    ORDER BY a.nombre;
    
SELECT * FROM vista1;

CREATE VIEW vista2 AS
	SELECT e.nombre AS "EVENTO", e.edicion AS "EDICION", e.ubicacion AS "UBICACION", 
    p.nombre AS "PONENTE", a.nombre AS "AREA"
	FROM evento e INNER JOIN participacionponente pe ON pe.IdEvento = e.IdEvento
    INNER JOIN ponentes p ON p.IdPonente = pe.IdPonente
    INNER JOIN areas a ON a.IdArea = p.IdArea
    ORDER BY e.edicion;
    
SELECT * FROM vista2;

CREATE VIEW vista3 AS
	SELECT e.nombre AS "EVENTO", e.edicion AS "EDICION",  u.nombre AS "UNIVERSIDAD", 
    a.titulo AS "TITULO DEL ARTICULO"
	FROM evento e INNER JOIN universidad u ON e.idUniversidad = u.idUniversidad
    INNER JOIN articulos a ON a.idUniversidad = u.idUniversidad
    ORDER BY e.edicion;
    
SELECT * FROM vista3;




/*********** STORE PROCEDURES *************/

-- SP1

DELIMITER #
CREATE PROCEDURE EVENTOSPORUNIVERSIDAD(IN UNIVERSIDADNAME VARCHAR(70)) 
BEGIN 
SELECT *
	FROM evento
	    JOIN universidad ON evento.idUniversidad = universidad.idUniversidad
	WHERE
	    universidad.nombre = universidadName;
END #

CALL EventosPorUniversidad("Singularity University Chile");

-- SP2

ALTER TABLE aliados ADD UNIQUE (nombre);
DELIMITER #
CREATE PROCEDURE INSERTARALIADO(IN NOMBREALIADO VARCHAR(20)) 
BEGIN 
	INSERT IGNORE INTO aliados(nombre) VALUES(nombrealiado);
	END #
CALL InsertarAliado("IBM");


-- SP3

DELIMITER #
CREATE PROCEDURE PONENTESPORAREA(IN ID_AREA VARCHAR(3)) 
BEGIN
	DECLARE area_exist INT DEFAULT 0;
	SELECT COUNT(*) INTO area_exist FROM Areas WHERE IdArea = id_area;
	IF area_exist > 0 THEN
	SELECT *
	FROM ponentes
	WHERE ponentes.IdArea = id_area;
	ELSE SELECT 'Área no válida' AS Resultado;
	END IF;
END #

CALL PonentesPorArea('LEV');

/**************Consultas***************/

--Consulta 1
select p.nombre
from Ponentes p
    inner join ponenteUni pu on pu.IdPonente = p.IdPonente
    inner join Universidad u on pu.idUniversidad = u.idUniversidad
    inner join Universidad_pais pa on pa.idUniversidad = u.idUniversidad
where pa.pais = "Alemania";

--Consulta 2
select pa.pais
from Universidad_pais pa
    inner join Universidad u on u.idUniversidad = pa.idUniversidad
    inner join ponenteUni pu on pu.idUniversidad = u.idUniversidad
    inner join Ponentes p on p.IdPonente = pu.IdPonente
    inner join Areas a on a.IdArea = p.IdArea
where
    a.nombre = "Arquitectura";

--Consulta 3
select pa.pais
from Universidad_pais pa
    inner join Universidad u on u.idUniversidad = pa.idUniversidad
    inner join Clientes cl on cl.idUniversidad = u.idUniversidad
    inner join Aliados al on al.IdAliado = cl.IdAliado
where al.nombre = "Coursera";

--Consulta 4
select
    p.nombre as "Ponente",
    COUNT(pa.pais) as "No. paises visitados"
from Ponentes p
    inner join ponenteUni pu on pu.IdPonente = p.IdPonente
    inner join Universidad u on u.idUniversidad = pu.idUniversidad
    inner join Universidad_pais pa on pa.idUniversidad = u.idUniversidad
group by p.nombre;

--Consulta 5
select
    p.nombre as "Ponente",
    COUNT(pp.IdEvento) as "No. de eventos"
from Ponentes p
    inner join participacionPonente pp on pp.IdPonente = p.IdPonente
group by pp.IdPonente;



/**************Triggers**************/
-- TGG 1
DELIMITER @
CREATE TRIGGER
    BefPonentes BEFORE
UPDATE
    ON Ponentes FOR EACH ROW BEGIN IF NEW.Educacion IS NULL THEN
SET
    NEW.Educacion = 'Not specified';
END IF;
END@ DELIMITER;
UPDATE ponentes SET nombre = 'Chayanne' WHERE IdPonente = 37;
SELECT * FROM ponentes;
INSERT INTO ponentes VALUES (37,"Chayanne",NULL,"RET");
SELECT * FROM ponentes;

--TGG 2
    
DELIMITER @
CREATE TRIGGER ALIADOINSERT AFTER INSERT ON ALIADOS 
FOR EACH ROW BEGIN 
	INSERT INTO
	    AliadoReg (IdAliado, nombre, fechaCambio)
	VALUES (
	        NEW.IdAliado,
	        NEW.nombre,
	        NOW()
	    );
	END @ 
INSERT INTO aliados (nombre) VALUES ('NuevoAliado');
SELECT * FROM AliadoReg;
SELECT * FROM aliados 