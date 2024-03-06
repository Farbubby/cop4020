interface WeLoveCOP4020 {
  sayIt(): void;
}

class Barista implements WeLoveCOP4020 {
  sayIt(): void {
    console.log("I love COP 4020 but I'm a barista.");
  }
}

class SoftwareEngineer implements WeLoveCOP4020 {
  sayIt(): void {
    console.log("I love COP 4020 and I am a software engineer.");
  }
}

class PsychologyMajor implements WeLoveCOP4020 {
  sayIt(): void {
    console.log("I love COP 4020 and I am a psychology major.");
  }
}

const barista = new Barista();
const softwareEngineer = new SoftwareEngineer();
const psychologyMajor = new PsychologyMajor();

barista.sayIt();
softwareEngineer.sayIt();
psychologyMajor.sayIt();
