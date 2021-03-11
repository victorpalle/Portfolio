FROM maven:3.5-jdk-8-alpine AS builder
WORKDIR /builder
COPY pom.xml .
COPY src/ /builder/src/
RUN mvn dependency:resolve
RUN mvn package


FROM openjdk:8-jre-alpine
WORKDIR /target
COPY --from=builder /builder/target/worker-jar-with-dependencies.jar /worker-jar-with-dependencies.jar
CMD ["java","-jar", "/target/worker-jar-with-dependencies.jar"]