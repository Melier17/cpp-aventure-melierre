# Game Design Document (GDD)
## cpp-aventure-melierre

**Versión:** 0.1 — Diseño conceptual  
**Estado:** En diseño; las mecánicas descritas no están implementadas todavía.  
**Tecnología prevista:** C++17, raylib 5.0, CMake y VS Code.  
**Repositorio:** [Melier17/cpp-aventure-melierre](https://github.com/Melier17/cpp-aventure-melierre)

---

## 1. Visión general

RPG 2D de perspectiva *top-down* que combina aventura, supervivencia, exploración, vida social, profesiones, construcción y multijugador. El mundo tendrá una ambientación de fantasía medieval con elementos *isekai* y una identidad narrativa original.

El objetivo es crear un mundo persistente en el que los jugadores puedan explorar, desarrollar personajes, formar comunidades, comerciar, construir y participar en expediciones. Las referencias del género sirven únicamente como inspiración general: no se copiarán personajes, mapas, historias, diseños ni propiedad intelectual de otras obras.

### 1.1 Pilares de diseño
- Exploración con descubrimientos y secretos.
- Progresión amplia y personalizable.
- Supervivencia y actividades cotidianas que aporten decisiones, sin convertirse en tareas repetitivas.
- Cooperación social mediante grupos y gremios.
- Economía de jugadores con controles contra abusos e inflación.
- Contenido PvE con mazmorras, expediciones y jefes.
- Monetización justa que no convierta el pago en una ventaja de poder.

### 1.2 Estructura del mundo
- Mundo abierto para exploración.
- Ciudades compartidas y espacios sociales.
- Mazmorras instanciadas, independientes para cada expedición.
- Modalidades individual, grupo privado, búsqueda automática y expedición de gremio.

---

## 2. Personajes y progresión (SYS-02)

### 2.1 Creación
- Creación híbrida: el jugador podrá crear un personaje desde cero o partir de un modelo prediseñado personalizable.
- Se contemplan múltiples razas; la lista definitiva y sus diferencias están pendientes de balance.
- Los arquetipos iniciales orientan el estilo de juego, pero no deben encerrar al jugador en una clase rígida.
- La lista final de razas, arquetipos, atributos y reglas de balance se definirá en una iteración posterior.

### 2.2 Atributos
Atributos propuestos para el sistema:
- Fuerza.
- Vitalidad.
- Agilidad.
- Inteligencia.
- Sabiduría.
- Destreza.

Sus efectos numéricos y límites se definirán mediante pruebas de balance.

### 2.3 Sistema de progresión híbrido — DECISIÓN APROBADA
La progresión será híbrida y combinará tres componentes:

1. **Niveles y experiencia:** el personaje obtiene experiencia mediante actividades relevantes, como misiones, exploración, combates, jefes, mazmorras, acertijos y eventos.
2. **Habilidades por uso:** las habilidades podrán mejorar cuando se utilicen de forma legítima y coherente con su función.
3. **Especializaciones:** el jugador podrá desbloquear caminos de especialización que orienten su estilo de juego y amplíen sus opciones.

Los niveles, las habilidades por uso y las especializaciones deberán complementarse sin permitir que una sola actividad repetitiva sea la vía dominante de progreso. Se aplicarán controles contra el farmeo abusivo y recompensas ajustadas a la dificultad y contribución.

**Parámetros provisionales, pendientes de pruebas:**
- Fórmula de experiencia sugerida: `EXP(n) = 100n² + 200n`, donde `n` es el nivel actual.
- Nivel máximo inicial sugerido: 50, ampliable en futuras actualizaciones.
- La fórmula, el límite, los atributos por nivel y los umbrales de desbloqueo no se consideran definitivos hasta probarlos.

---

## 3. Supervivencia, recolección y vivienda (SYS-06)

### 3.1 Necesidades y entorno
Se contemplan hambre, sed, energía, descanso, temperatura y condiciones ambientales. El clima podrá incluir sol, lluvia, tormentas, nieve, niebla y extremos de temperatura.

Las necesidades deberán aportar decisiones y planificación sin castigar de forma desproporcionada a quien explore o juegue en sesiones cortas.

### 3.2 Recolección y actividades
- Recursos comunes disponibles mediante recolección.
- Recursos especiales sujetos a herramientas, habilidades o condiciones.
- Actividades previstas: minería, pesca, agricultura, tala y recolección de plantas.

### 3.3 Vivienda
Se contempla construir y administrar terrenos, refugios, casas, granjas, talleres, tiendas e instalaciones gremiales. Las propiedades tendrán personalización, persistencia y permisos diferenciados para propietario, administrador, invitado y visitante.

### 3.4 Derrota
La derrota normal no causará pérdida permanente del personaje, niveles ni propiedades. Se contempla recuperación y, si el balance lo requiere, una penalización temporal moderada.

---

## 4. Profesiones, cocina y fabricación (SYS-07)

Cada personaje podrá elegir una profesión principal y desarrollar habilidades o profesiones secundarias sin un límite rígido establecido.

Profesiones contempladas: herrero, cocinero, alquimista, artesano, agricultor, sastre, carpintero y joyero.

La fabricación podrá requerir recetas o planos, materias primas, herramientas, estaciones de trabajo, nivel de habilidad y tiempo. Algunas recetas especiales podrán descubrirse mediante exploración, misiones o intercambio. Las reglas de calidad, tiempos y progresión quedan pendientes de balance.

---

## 5. Comunicación y comunidad (SYS-08 y SYS-09)

### 5.1 Comunicación
Se contempla chat global, local, privado, de grupo, de gremio y de comercio. El sistema incluirá controles de silenciar, bloquear y reportar, filtros de lenguaje y medidas contra spam y abuso.

### 5.2 Gremios
Los jugadores podrán crear y administrar gremios con nombre, emblema, descripción, miembros, rangos, reputación y actividades colectivas.

Rangos propuestos: Maestro, Administrador, Oficial, Veterano, Miembro y Aspirante. Los permisos deberán ser configurables y quedar registrados.

Actividades previstas: expediciones, producción, proyectos colectivos, comercio y administración de instalaciones. El gremio contará con chat y tesorería compartida, separada de las carteras personales.

### 5.3 Tecnologías gremiales por especialización — DECISIÓN APROBADA
El árbol tecnológico tendrá cinco ramas:

1. **Militar:** entrenamiento, coordinación, defensa y estrategias.
2. **Exploración:** cartografía, detección de secretos y expediciones.
3. **Economía:** comercio, producción y almacenamiento.
4. **Artesanía:** fabricación, herramientas y estaciones de trabajo.
5. **Infraestructura:** edificios, instalaciones y expansión territorial.

**Regla aprobada:** cada gremio deberá priorizar y especializarse en determinadas ramas. No tendrá acceso inmediato ni desarrollo libre e ilimitado de todas las ramas al mismo ritmo. Esta elección dará identidad estratégica a cada gremio y fomentará cooperación e intercambio entre comunidades.

Las investigaciones podrán exigir prerrequisitos, recursos, tiempo, instalaciones y autorización de un rango habilitado. Los beneficios deberán ser moderados y equilibrados.

**Puntos de Valor Gremial (PVG):** nombre provisional para los puntos colectivos de investigación. Son distintos de los puntos de vida (PV), pertenecen al gremio, no se compran con dinero real y no se transfieren entre gremios. Las fuentes de obtención y los costos por nivel quedan sujetos a balance.

Las tecnologías y sus registros deberán persistir aunque cambie el líder. Las contribuciones, gastos y responsables deberán poder auditarse.

---

## 6. Economía y comercio (SYS-10)

### 6.1 Monedas
- Moneda principal propuesta: oro.
- Monedas especiales para eventos o sistemas concretos.
- La incorporación de monedas regionales no está aprobada y queda pendiente.

### 6.2 Modalidades comerciales
- Comercio directo entre jugadores.
- Mercado general con publicaciones y filtros.
- Tiendas permanentes administradas por gremios.

Los jugadores individuales podrán participar en el comercio directo y el mercado general. Las tiendas permanentes serán una función de los gremios.

### 6.3 Finanzas
Cada jugador tendrá una cartera personal. Cada gremio tendrá una tesorería separada con permisos para depositar, retirar y consultar movimientos. Las operaciones deberán mantener un historial verificable.

Los precios podrán responder a oferta, demanda, región, rareza, calidad, transporte y actividad económica. Se estudiarán tarifas, comisiones y costos de mantenimiento para reducir la inflación.

Toda operación económica deberá validarse en el servidor y contar con protección contra duplicación y manipulación.

---

## 7. Compañeros, mascotas y criaturas (SYS-11)

Se contemplan tres categorías:
- Mascotas.
- Criaturas fantásticas.
- Compañeros especiales vinculados a misiones o historias.

La adquisición se realizará principalmente mediante misiones, eventos, logros, reputación y recompensas. No se ha aprobado la domesticación libre como método general.

Los compañeros podrán apoyar tanto en combate como en actividades: exploración, recolección, supervivencia y transporte. Tendrán ficha, habilidades, comportamiento configurable y estado.

### 7.1 Progresión de compañeros
Los compañeros tendrán progresión propia: experiencia, niveles, habilidades, especializaciones y vínculo. Obtendrán experiencia al participar o contribuir en combates, expediciones, recolección, exploración y misiones.

Algunas especies podrán evolucionar al cumplir condiciones específicas, como nivel, vínculo, misiones, materiales o requisitos propios de la especie. La evolución no será universal.

La derrota normal no provocará muerte permanente del compañero; podrá quedar temporalmente incapacitado y requerir recuperación.

---

## 8. Mazmorras y expediciones (SYS-12)

### 8.1 Diseño y generación
Se combinarán mazmorras diseñadas manualmente con generación procedural controlada. La generación deberá respetar reglas de coherencia, dificultad, navegación y calidad; no será aleatoria sin restricciones.

Las mazmorras serán instancias separadas. Modalidades: individual, grupo privado, búsqueda automática y expedición de gremio.

### 8.2 Dificultades y pisos
Dificultades previstas:
- Fácil: 3 pisos.
- Normal: 5 pisos.
- Difícil: 7 pisos.
- Experto: 10 pisos.
- Legendario: 15 pisos.

Los valores podrán ajustarse durante el balance. Cada piso podrá contener enemigos, cofres, recursos, secretos, trampas, acertijos y eventos. Cada piso tendrá un jefe guardián; al derrotarlo se activará un portal al siguiente piso y se sincronizará el progreso del grupo. El último piso tendrá el jefe final.

### 8.3 Jefes y elementos
Categorías de jefes: normales, regionales, legendarios y elementales. Estas categorías podrán combinarse.

Diez elementos principales aprobados:
- Fuego, Hielo, Agua, Tierra, Rayo, Aire, Naturaleza, Oscuridad, Luz y Arcano.

Los jefes podrán tener afinidades, resistencias, vulnerabilidades, patrones, fases y habilidades elementales. Se contemplan combinaciones elementales y afinidades ocultas que puedan descubrirse mediante exploración, misiones o investigación.

### 8.4 Recompensas y rareza
Rarezas aprobadas:
- Común I.
- Raro II.
- Épico III.
- Legendario IV.
- Mítico V.
- Divino VI.

Recompensas posibles: oro y monedas, materiales, equipamiento, recetas, consumibles, gemas elementales, cofres y objetos únicos. Las gemas podrán utilizarse en equipamiento, fabricación y evolución de materiales o artefactos.

Los objetos Divinos serán extremadamente exclusivos y podrán obtenerse mediante jefes legendarios, misiones únicas, historias y acontecimientos. No podrán comprarse directamente con dinero real.

Se contemplan botín individual, botín compartido y reparto por necesidad; sus reglas exactas quedan pendientes.

### 8.5 Trampas, secretos y pisos especiales
Trampas previstas: mecánicas, mágicas, ambientales, ilusorias, de acertijo y guardianes. Podrán detectarse, evitarse, desactivarse o resolverse con habilidades, herramientas o compañeros.

Pisos especiales posibles: tesoro, jefe secundario, acertijos, recursos raros, supervivencia y zonas secretas. No todos aparecerán obligatoriamente en cada mazmorra; algunos contenidos serán exclusivos de mazmorras narrativas.

### 8.6 Cierre de instancia
Tras derrotar al jefe final comenzará una cuenta regresiva para explorar y recoger recompensas. Antes de eliminar la instancia, el servidor registrará el progreso y las recompensas, trasladará a los jugadores a una zona segura y luego destruirá la instancia. La duración de la cuenta regresiva y los detalles de evacuación quedan pendientes.

---

## 9. Monetización y sostenibilidad

El juego deberá poder disfrutarse sin pagar y evitar ventajas competitivas de pago (*pay-to-win*).

Modelos contemplados:
- Cosméticos para personajes y compañeros.
- Decoración y personalización de viviendas.
- Pase de temporada con recompensas principalmente cosméticas.
- Expansiones y contenido adicional.
- Edición premium o paquetes opcionales.

No se venderán directamente objetos Divinos ni poder máximo. La estrategia comercial deberá considerar costos de servidores, mantenimiento, moderación, soporte, comisiones, impuestos y actualizaciones. Los precios y el modelo definitivo se decidirán después de validar el alcance y los costos reales.

---

## 10. Requisitos transversales de calidad

- Arquitectura modular y extensible.
- Persistencia fiable de personajes, propiedades, gremios, inventarios y economía.
- Validación en servidor para operaciones multijugador, recompensas y transacciones.
- Protección contra duplicación, manipulación y abuso.
- Sincronización y recuperación razonable ante desconexiones.
- Permisos y registros de auditoría para acciones administrativas.
- Rendimiento adecuado en mundo abierto e instancias.
- Herramientas de moderación y protección de la comunidad.

---

## 11. Estado del diseño y próximos pasos

Este documento consolida decisiones aprobadas y propuestas de diseño. No significa que las funciones estén programadas ni probadas.

**Decisiones aprobadas especialmente relevantes en esta revisión:**
- Progresión híbrida del personaje: niveles/experiencia, habilidades por uso y especializaciones.
- Tecnologías gremiales con especialización de ramas: cada gremio prioriza ramas del árbol tecnológico.

**Pendiente de definición y validación:**
- Lista definitiva de razas, arquetipos y efectos de atributos.
- Fórmulas y límites de progresión, experiencia y balance.
- Costos y requisitos finales de tecnologías gremiales.
- Reglas completas de profesiones, fabricación y calidad.
- Tarifas, fuentes de monedas y controles económicos.
- Duración de evacuación y balance de mazmorras.
- Arquitectura de red, persistencia y seguridad multijugador.
- Alcance técnico de la primera versión jugable.

**Principio de producción:** primero cerrar el diseño esencial, después implementar una base técnica pequeña y verificable, y ampliar los sistemas por etapas. La versión 0.1 jugable deberá priorizar ventana, movimiento, cámara, mapa y colisiones antes de abordar los sistemas online complejos.
