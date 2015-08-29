DROP TABLE Categoria;
DROP TABLE Pictograma;
CREATE TABLE 'Categoria'(
Nombre VARCHAR(512),
Icono VARCHAR(2048),
CONSTRAINT PKCategoria PRIMARY KEY(Nombre)
);

INSERT INTO Categoria VALUES('Acciones',	'img/ePictograma/logoCat/acciones.png');
INSERT INTO Categoria VALUES('Cortesia',	'img/ePictograma/logoCat/cortesia.png');
INSERT INTO Categoria VALUES('Descripcion',	'img/ePictograma/logoCat/descripcion.png');
INSERT INTO Categoria VALUES('Emociones',	'img/ePictograma/logoCat/emociones.png');
INSERT INTO Categoria VALUES('Frases',	'img/ePictograma/logoCat/frases.png');
INSERT INTO Categoria VALUES('Otros',	'img/ePictograma/logoCat/otros.png');
INSERT INTO Categoria VALUES('Personas',	'img/ePictograma/logoCat/personas.png');
INSERT INTO Categoria VALUES('Preguntas',	'img/ePictograma/logoCat/preguntas.png');
INSERT INTO Categoria VALUES('Sustantivos',	'img/ePictograma/logoCat/sustantivos.png');


CREATE TABLE 'Pictograma'(
Descripcion VARCHAR(256),
NombreCat VARCHAR(512),
Icono VARCHAR(2048),
CONSTRAINT PKPictograma PRIMARY KEY(Descripcion, NombreCat),
CONSTRAINT PKPictogramaCategoria FOREIGN KEY(NombreCat) REFERENCES Categoria(Nombre)
);

-- pictogramas de la categoria Acciones
INSERT INTO Pictograma VALUES('acostarse','Acciones','img/ePictograma/catAcciones/acostarse en la cama.png');
INSERT INTO Pictograma VALUES('cepillarse','Acciones','img/ePictograma/catAcciones/cepillarse los dientes.png');
INSERT INTO Pictograma VALUES('comprar','Acciones','img/ePictograma/catAcciones/comprar.png');
INSERT INTO Pictograma VALUES('dar la mano','Acciones','img/ePictograma/catAcciones/dar la mano.png');
INSERT INTO Pictograma VALUES('decidir','Acciones','img/ePictograma/catAcciones/decidir.png');
INSERT INTO Pictograma VALUES('dormir','Acciones','img/ePictograma/catAcciones/dormir.png');
INSERT INTO Pictograma VALUES('escuchar','Acciones','img/ePictograma/catAcciones/escuchar.png');
INSERT INTO Pictograma VALUES('estar acostado','Acciones','img/ePictograma/catAcciones/estar acostado.png');
INSERT INTO Pictograma VALUES('fotografiar','Acciones','img/ePictograma/catAcciones/fotografiar.png');
INSERT INTO Pictograma VALUES('golpear','Acciones','img/ePictograma/catAcciones/golpear.png');
INSERT INTO Pictograma VALUES('gustar','Acciones','img/ePictograma/catAcciones/gustar.png');
INSERT INTO Pictograma VALUES('hambre','Acciones','img/ePictograma/catAcciones/hambre.png');
INSERT INTO Pictograma VALUES('ir','Acciones','img/ePictograma/catAcciones/ir.png');
INSERT INTO Pictograma VALUES('leer','Acciones','img/ePictograma/catAcciones/leer.png');
INSERT INTO Pictograma VALUES('nadar','Acciones','img/ePictograma/catAcciones/nadar.png');
INSERT INTO Pictograma VALUES('pagar','Acciones','img/ePictograma/catAcciones/pagar.png');
INSERT INTO Pictograma VALUES('quiero hacer','Acciones','img/ePictograma/catAcciones/quiero hacer.png');
INSERT INTO Pictograma VALUES('quiero ir a','Acciones','img/ePictograma/catAcciones/Quiero ir a.png');
INSERT INTO Pictograma VALUES('recibir','Acciones','img/ePictograma/catAcciones/recibir.png');
INSERT INTO Pictograma VALUES('recordar','Acciones','img/ePictograma/catAcciones/recordar.png');
INSERT INTO Pictograma VALUES('ver','Acciones','img/ePictograma/catAcciones/ver.png');
INSERT INTO Pictograma VALUES('verse','Acciones','img/ePictograma/catAcciones/verse.png');
INSERT INTO Pictograma VALUES('yo amo','Acciones','img/ePictograma/catAcciones/Yo amo.png');
INSERT INTO Pictograma VALUES('yo quiero','Acciones','img/ePictograma/catAcciones/Yo quiero.png');

-- pictogramas de la categoria Cortesia
INSERT INTO Pictograma VALUES('adios','Cortesia','img/ePictograma/catCortesia/adios.png');
INSERT INTO Pictograma VALUES('como esta','Cortesia','img/ePictograma/catCortesia/como esta.png');
INSERT INTO Pictograma VALUES('dar la mano','Cortesia','img/ePictograma/catCortesia/dar la mano.png');
INSERT INTO Pictograma VALUES('gracias','Cortesia','img/ePictograma/catCortesia/gracias.png');
INSERT INTO Pictograma VALUES('¡Feliz Cumple!','Cortesia','img/ePictograma/catCortesia/felizc.png');
INSERT INTO Pictograma VALUES('hola','Cortesia','img/ePictograma/catCortesia/hola.png');
INSERT INTO Pictograma VALUES('perdon','Cortesia','img/ePictograma/catCortesia/perdon.png');
INSERT INTO Pictograma VALUES('¡provecho!','Cortesia','img/ePictograma/catCortesia/provecho.png');

-- pictogramas de la categoria descripcion
INSERT INTO Pictograma VALUES('bonito','Descripcion','img/ePictograma/catDescripcion/bonito.png');
INSERT INTO Pictograma VALUES('agradable','Descripcion','img/ePictograma/catDescripcion/agradable.png');
INSERT INTO Pictograma VALUES('delgado','Descripcion','img/ePictograma/catDescripcion/delgado.png');
INSERT INTO Pictograma VALUES('feo','Descripcion','img/ePictograma/catDescripcion/feo.png');
INSERT INTO Pictograma VALUES('gordo','Descripcion','img/ePictograma/catDescripcion/gordo.png');
INSERT INTO Pictograma VALUES('grande','Descripcion','img/ePictograma/catDescripcion/grande.png');
INSERT INTO Pictograma VALUES('pequeno','Descripcion','img/ePictograma/catDescripcion/pequeno.png');
INSERT INTO Pictograma VALUES('colores','Descripcion','img/ePictograma/catDescripcion/colores.png');
INSERT INTO Pictograma VALUES('amarillo','Descripcion','img/ePictograma/catDescripcion/amarillo.png');
INSERT INTO Pictograma VALUES('azul claro','Descripcion','img/ePictograma/catDescripcion/azul claro.png');
INSERT INTO Pictograma VALUES('azul','Descripcion','img/ePictograma/catDescripcion/azul.png');
INSERT INTO Pictograma VALUES('blanco','Descripcion','img/ePictograma/catDescripcion/blanco.png');
INSERT INTO Pictograma VALUES('negro','Descripcion','img/ePictograma/catDescripcion/negro.png');
INSERT INTO Pictograma VALUES('rojo','Descripcion','img/ePictograma/catDescripcion/rojo.png');
INSERT INTO Pictograma VALUES('verde claro','Descripcion','img/ePictograma/catDescripcion/verde claro.png');
INSERT INTO Pictograma VALUES('verde oscuro','Descripcion','img/ePictograma/catDescripcion/verde oscuro.png');

-- pictogramas de la categoria Emociones
INSERT INTO Pictograma VALUES('feliz','Emociones','img/ePictograma/catEmociones/feliz.png');
INSERT INTO Pictograma VALUES('irritado','Emociones','img/ePictograma/catEmociones/irritado.png');
INSERT INTO Pictograma VALUES('miedo','Emociones','img/ePictograma/catEmociones/miedo.png');
INSERT INTO Pictograma VALUES('enamorados','Emociones','img/ePictograma/catEmociones/enamorados.png');
INSERT INTO Pictograma VALUES('reir','Emociones','img/ePictograma/catEmociones/reir.png');
INSERT INTO Pictograma VALUES('llorar','Emociones','img/ePictograma/catEmociones/llorar.png');
INSERT INTO Pictograma VALUES('triste','Emociones','img/ePictograma/catEmociones/triste.png');
INSERT INTO Pictograma VALUES('sorprendido','Emociones','img/ePictograma/catEmociones/sorprendido.png');

-- píctogramas de la categoria Frases
INSERT INTO Pictograma VALUES('¡no toque!','Frases','img/ePictograma/catFrases/no toque.png');
INSERT INTO Pictograma VALUES('¡bien!','Frases','img/ePictograma/catFrases/bien.png');
INSERT INTO Pictograma VALUES('¡no me moleste!','Frases','img/ePictograma/catFrases/no me moleste.png');
INSERT INTO Pictograma VALUES('¡que chapa!','Frases','img/ePictograma/catFrases/que chapa.jpg');
INSERT INTO Pictograma VALUES('chicago fire','Frases','img/ePictograma/catFrases/Chicago Fire.jpg');
INSERT INTO Pictograma VALUES('combate','Frases','img/ePictograma/catFrases/Combate.jpg');
INSERT INTO Pictograma VALUES('el precio de la hist','Frases','img/ePictograma/catFrases/El precio.jpg');
INSERT INTO Pictograma VALUES('locos por los autos','Frases','img/ePictograma/catFrases/Locos.jpg');
INSERT INTO Pictograma VALUES('¡viva Saprissa!','Frases','img/ePictograma/catFrases/viva.jpg');
INSERT INTO Pictograma VALUES('¡quiero estar solo!','Frases','img/ePictograma/catFrases/solo.png');
INSERT INTO Pictograma VALUES('quiero decir','Frases','img/ePictograma/catFrases/decir.png');
INSERT INTO Pictograma VALUES('me molesta','Frases','img/ePictograma/catFrases/molesta.png');
INSERT INTO Pictograma VALUES('prestar atencion','Frases','img/ePictograma/catFrases/atencion.png');
INSERT INTO Pictograma VALUES('estoy confundido','Frases','img/ePictograma/catFrases/confundido.png');
INSERT INTO Pictograma VALUES('me duele','Frases','img/ePictograma/catFrases/Me duele.png');
INSERT INTO Pictograma VALUES('calle','Frases','img/ePictograma/catFrases/calle.png');
INSERT INTO Pictograma VALUES('centro comercial','Frases','img/ePictograma/catFrases/centro comercial.png');
INSERT INTO Pictograma VALUES('cine','Frases','img/ePictograma/catFrases/cine.png');
INSERT INTO Pictograma VALUES('playa','Frases','img/ePictograma/catFrases/playa.png');
INSERT INTO Pictograma VALUES('restaurante','Frases','img/ePictograma/catFrases/restaurante.png');
INSERT INTO Pictograma VALUES('dolor de cabeza','Frases','img/ePictograma/catFrases/dolor de cabeza.png');
INSERT INTO Pictograma VALUES('dolor de espalda','Frases','img/ePictograma/catFrases/dolor de espalda.png');
INSERT INTO Pictograma VALUES('dolor de estomago','Frases','img/ePictograma/catFrases/dolor de estomago.png');
INSERT INTO Pictograma VALUES('dolor de muela','Frases','img/ePictograma/catFrases/dolor de muela.png');
INSERT INTO Pictograma VALUES('escuela','Frases','img/ePictograma/catFrases/escuela.png');
INSERT INTO Pictograma VALUES('enfermo','Frases','img/ePictograma/catFrases/enfermo.png');
INSERT INTO Pictograma VALUES('pierna','Frases','img/ePictograma/catFrases/pierna.png');
INSERT INTO Pictograma VALUES('pies','Frases','img/ePictograma/catFrases/pies.png');

-- pictogramas de la categoria Otros
INSERT INTO Pictograma VALUES('antes','Otros','img/ePictograma/catOtros/antes.png');
INSERT INTO Pictograma VALUES('despues','Otros','img/ePictograma/catOtros/despues.png');
INSERT INTO Pictograma VALUES('¡esta nublado!','Otros','img/ePictograma/catOtros/esta nublado.png');
INSERT INTO Pictograma VALUES('¡hace aire!','Otros','img/ePictograma/catOtros/hace aire.png');
INSERT INTO Pictograma VALUES('¡hace sol!','Otros','img/ePictograma/catOtros/hace sol.png');
INSERT INTO Pictograma VALUES('¡hay nubes!','Otros','img/ePictograma/catOtros/hay nubes.png');
INSERT INTO Pictograma VALUES('¡hay viento!','Otros','img/ePictograma/catOtros/hay viento.png');
INSERT INTO Pictograma VALUES('¡llueve!','Otros','img/ePictograma/catOtros/llueve.png');

-- pictogramas de la categoria Personas
INSERT INTO Pictograma VALUES('mama','Personas','img/ePictograma/catPersonas/mama.png');
INSERT INTO Pictograma VALUES('papa','Personas','img/ePictograma/catPersonas/papa.png');
INSERT INTO Pictograma VALUES('hermana','Personas','img/ePictograma/catPersonas/hermana.png');
INSERT INTO Pictograma VALUES('hermano','Personas','img/ePictograma/catPersonas/hermano.png');
INSERT INTO Pictograma VALUES('bebe','Personas','img/ePictograma/catPersonas/bebe.png');
INSERT INTO Pictograma VALUES('abuela','Personas','img/ePictograma/catPersonas/abuela.png');
INSERT INTO Pictograma VALUES('abuelo','Personas','img/ePictograma/catPersonas/abuelo.png');
INSERT INTO Pictograma VALUES('abuelos','Personas','img/ePictograma/catPersonas/abuelos.png');
INSERT INTO Pictograma VALUES('familia','Personas','img/ePictograma/catPersonas/familia.png');
INSERT INTO Pictograma VALUES('fisioterapeuta','Personas','img/ePictograma/catPersonas/fisioterapeuta.png');
INSERT INTO Pictograma VALUES('profesora','Personas','img/ePictograma/catPersonas/profesora.png');
INSERT INTO Pictograma VALUES('profesor','Personas','img/ePictograma/catPersonas/profesor.png');

-- pictogramas de la categoria Preguntas
INSERT INTO Pictograma VALUES('cual es tu nombre','Preguntas','img/ePictograma/catPreguntas/cual es tu nombre.png');
INSERT INTO Pictograma VALUES('cual','Preguntas','img/ePictograma/catPreguntas/cual.png');
INSERT INTO Pictograma VALUES('donde','Preguntas','img/ePictograma/catPreguntas/cuando.png');
INSERT INTO Pictograma VALUES('donde vamos','Preguntas','img/ePictograma/catPreguntas/donde vamos.png');
INSERT INTO Pictograma VALUES('estas asustado','Preguntas','img/ePictograma/catPreguntas/estas asustado.png');
INSERT INTO Pictograma VALUES('estas contento','Preguntas','img/ePictograma/catPreguntas/estas contento.png');
INSERT INTO Pictograma VALUES('estas enfadado','Preguntas','img/ePictograma/catPreguntas/estas enfadado.png');
INSERT INTO Pictograma VALUES('estas triste','Preguntas','img/ePictograma/catPreguntas/estas triste.png');
INSERT INTO Pictograma VALUES('no entiendo','Preguntas','img/ePictograma/catPreguntas/no entiendo lo que dices.png');
INSERT INTO Pictograma VALUES('por que','Preguntas','img/ePictograma/catPreguntas/por que.png');
INSERT INTO Pictograma VALUES('pregunta','Preguntas','img/ePictograma/catPreguntas/pregunta.png');
INSERT INTO Pictograma VALUES('que dijo','Preguntas','img/ePictograma/catPreguntas/que dijo.png');
INSERT INTO Pictograma VALUES('que es eso','Preguntas','img/ePictograma/catPreguntas/que es eso.png');
INSERT INTO Pictograma VALUES('que estudia','Preguntas','img/ePictograma/catPreguntas/que estudia.png');
INSERT INTO Pictograma VALUES('que ha hecho','Preguntas','img/ePictograma/catPreguntas/que ha hecho.png');
INSERT INTO Pictograma VALUES('que hora es','Preguntas','img/ePictograma/catPreguntas/que hora es.png');
INSERT INTO Pictograma VALUES('que juego quiere','Preguntas','img/ePictograma/catPreguntas/que juego quiere.png');
INSERT INTO Pictograma VALUES('cual programa','Preguntas','img/ePictograma/catPreguntas/que programa quiere ver.png');
INSERT INTO Pictograma VALUES('que tiempo hace','Preguntas','img/ePictograma/catPreguntas/que tiempo hace.png');
INSERT INTO Pictograma VALUES('que tiene','Preguntas','img/ePictograma/catPreguntas/que tiene.png');

-- pictogramas de la categoria Sustantivos
INSERT INTO Pictograma VALUES('arbol','Sustantivos','img/ePictograma/catSustantivos/arbol.png');
INSERT INTO Pictograma VALUES('arco iris','Sustantivos','img/ePictograma/catSustantivos/arco iris.png');
INSERT INTO Pictograma VALUES('ardilla','Sustantivos','img/ePictograma/catSustantivos/ardilla.png');
INSERT INTO Pictograma VALUES('auto','Sustantivos','img/ePictograma/catSustantivos/auto.png');
INSERT INTO Pictograma VALUES('autobus','Sustantivos','img/ePictograma/catSustantivos/autobus.png');
INSERT INTO Pictograma VALUES('avion','Sustantivos','img/ePictograma/catSustantivos/avion.png');
INSERT INTO Pictograma VALUES('bano','Sustantivos','img/ePictograma/catSustantivos/bano.png');
INSERT INTO Pictograma VALUES('camisa','Sustantivos','img/ePictograma/catSustantivos/camisa.png');
INSERT INTO Pictograma VALUES('casa','Sustantivos','img/ePictograma/catSustantivos/casa.png');
INSERT INTO Pictograma VALUES('celular','Sustantivos','img/ePictograma/catSustantivos/celular.png');
INSERT INTO Pictograma VALUES('comida','Sustantivos','img/ePictograma/catSustantivos/comida.png');
INSERT INTO Pictograma VALUES('computadora','Sustantivos','img/ePictograma/catSustantivos/computadora.png');
INSERT INTO Pictograma VALUES('cucaracha','Sustantivos','img/ePictograma/catSustantivos/cucaracha.png');
INSERT INTO Pictograma VALUES('dinero','Sustantivos','img/ePictograma/catSustantivos/dinero.png');
INSERT INTO Pictograma VALUES('escuela','Sustantivos','img/ePictograma/catSustantivos/escuela.png');
INSERT INTO Pictograma VALUES('fiesta','Sustantivos','img/ePictograma/catSustantivos/fiesta.png');
INSERT INTO Pictograma VALUES('fruta','Sustantivos','img/ePictograma/catSustantivos/fruta.png');
INSERT INTO Pictograma VALUES('futbol','Sustantivos','img/ePictograma/catSustantivos/futbol.png');
INSERT INTO Pictograma VALUES('gato','Sustantivos','img/ePictograma/catSustantivos/gato.png');
INSERT INTO Pictograma VALUES('golosinas','Sustantivos','img/ePictograma/catSustantivos/golosinas.png');
INSERT INTO Pictograma VALUES('internet','Sustantivos','img/ePictograma/catSustantivos/internet.png');
INSERT INTO Pictograma VALUES('libro','Sustantivos','img/ePictograma/catSustantivos/libro.png');
INSERT INTO Pictograma VALUES('musica','Sustantivos','img/ePictograma/catSustantivos/musica.png');
INSERT INTO Pictograma VALUES('pantalon','Sustantivos','img/ePictograma/catSustantivos/pantalon.png');
INSERT INTO Pictograma VALUES('pelicula','Sustantivos','img/ePictograma/catSustantivos/pantalon.png');
INSERT INTO Pictograma VALUES('perro','Sustantivos','img/ePictograma/catSustantivos/perro.png');
INSERT INTO Pictograma VALUES('silla de ruedas','Sustantivos','img/ePictograma/catSustantivos/silla de ruedas.png');
INSERT INTO Pictograma VALUES('tablet','Sustantivos','img/ePictograma/catSustantivos/tablet.png');
INSERT INTO Pictograma VALUES('tarea','Sustantivos','img/ePictograma/catSustantivos/tarea.png');
INSERT INTO Pictograma VALUES('television','Sustantivos','img/ePictograma/catSustantivos/Tele.png');
INSERT INTO Pictograma VALUES('zapatos de tacon','Sustantivos','img/ePictograma/catSustantivos/zapatos de tacon.png');
INSERT INTO Pictograma VALUES('zapatos','Sustantivos','img/ePictograma/catSustantivos/zapatos.png');

SELECT COUNT(*) FROM Pictograma;
SELECT * FROM Pictograma;
SELECT * FROM Categoria;

