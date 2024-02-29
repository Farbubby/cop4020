interface Candy {
  name: string;
  price: number;
  flavor: string;
  description(): void;
}

class Hershey implements Candy {
  name = "Hershey";
  price = 1.0;
  flavor = "Sweet";
  description() {
    console.log(
      `The price of ${this.name} is $${this.price} and it's flavor is ${this.flavor}`
    );
  }
}

class SourPatch implements Candy {
  name = "Sour Patch";
  price = 1.5;
  flavor = "Sour";
  description() {
    console.log(
      `The price of ${this.name} is $${this.price} and it's flavor is ${this.flavor}`
    );
  }
}

class CandyFactory {
  createCandy(type: string): Candy {
    if (type === "Hershey") {
      return new Hershey();
    } else if (type === "Sour Patch") {
      return new SourPatch();
    } else {
      throw new Error("Candy not found");
    }
  }
}

const candyFactory = new CandyFactory();

const hersheyCandy = candyFactory.createCandy("Hershey");
hersheyCandy.description();

const sourPatchCandy = candyFactory.createCandy("Sour Patch");
sourPatchCandy.description();
