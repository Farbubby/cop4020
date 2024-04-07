class Animal {
    public void move() {
        Console.WriteLine("Animal is moving");
    }

    public void sleep() {
        Console.WriteLine("Animal is sleeping");
    }

    public void eat() {
        Console.WriteLine("Animal is eating");
    }
}

class Dog : Animal{
    public void sing() {
        Console.WriteLine("Dog is singing");
    }

    public void wash() {
        Console.WriteLine("Dog is washing");
    }

    public void turnAround() {
        Console.WriteLine("Dog is turning around");
    
    }
}

class Cat : Animal {
    public void sing() {
        Console.WriteLine("Cat is singing");
    }

    public void wash() {
        Console.WriteLine("Cat is washing");
    }

    public void turnAround() {
        Console.WriteLine("Cat is turning around");
    }
}

class Bird : Animal {
    public void sing() {
        Console.WriteLine("Bird is singing");
    }

    public void wash() {
        Console.WriteLine("Bird is washing");
    }

    public void turnAround() {
        Console.WriteLine("Bird is turning around");
    }
}

interface IUFO {
    void fly();
    void goToHyperSpace();
    void land();
}

class SmallCraft : IUFO {
    public void fly() {
        Console.WriteLine("SmallCraft is flying");
    }

    public void goToHyperSpace() {
        Console.WriteLine("SmallCraft is going to hyperspace");
    }

    public void land() {
        Console.WriteLine("SmallCraft is landing");
    }
}

class LargeCraft : IUFO {
    public void fly() {
        Console.WriteLine("LargeCraft is flying");
    }

    public void goToHyperSpace() {
        Console.WriteLine("LargeCraft is going to hyperspace");
    }

    public void land() {
        Console.WriteLine("LargeCraft is landing");
    }
}

class BossCraft : IUFO {
    public void fly() {
        Console.WriteLine("BossCraft is flying");
    }

    public void goToHyperSpace() {
        Console.WriteLine("BossCraft is going to hyperspace");
    }

    public void land() {
        Console.WriteLine("BossCraft is landing");
    }
}

class Problem1 {
    public static IEnumerable<int> myFilter(IEnumerable<int> input) {
        List<int> result = new List<int>();
        foreach (int i in input) {
            if (!((i % 5 == 0 && i > 50) || (Math.Pow(i, 3) % 2 == 0))) {
                result.Add((int)Math.Pow(i, 3));
            }
        }
        return result;
    }
}

class Problem2 {
    public static IEnumerable<int> myFilter(IEnumerable<int> input) {
        List<int> result = new List<int>();
        foreach (int i in input) {
            if (!((i % 6 == 0 && i < 42) || (Math.Pow(i, 2) % 2 != 0))) {
                result.Add((int)Math.Pow(i, 2));
            }
        }
        return result;
    }

}

class Problem3 {
    public static IEnumerable<int> myFilter(IEnumerable<int> input1, IEnumerable<int> input2, IEnumerable<int> input3, IEnumerable<int> input4) {
        IEnumerable<int> mergedSequence = input1
            .Intersect(input2)
            .Intersect(input3)
            .Intersect(input4)
            .Where(num => num % 10 == 0);

        return mergedSequence;
    }

}

class Program {
    static void Main(string[] args) {
        Console.WriteLine("\n======== Part 1 ========");
        Dog dog = new Dog();
        Cat cat = new Cat();
        Bird bird = new Bird();

        dog.move();
        dog.sleep();
        dog.eat();
        dog.sing();
        dog.wash();
        dog.turnAround();

        Console.WriteLine();

        cat.move();
        cat.sleep();
        cat.eat();
        cat.sing();
        cat.wash();
        cat.turnAround();

        Console.WriteLine();

        bird.move();
        bird.sleep();
        bird.eat();
        bird.sing();
        bird.wash();
        bird.turnAround();

        Console.WriteLine("\n======== Part 2 ========");
        SmallCraft smallCraft = new SmallCraft();
        LargeCraft largeCraft = new LargeCraft();
        BossCraft bossCraft = new BossCraft();

        smallCraft.fly();
        smallCraft.goToHyperSpace();
        smallCraft.land();

        Console.WriteLine();

        largeCraft.fly();
        largeCraft.goToHyperSpace();
        largeCraft.land();

        Console.WriteLine();

        bossCraft.fly();
        bossCraft.goToHyperSpace();
        bossCraft.land();

        Console.WriteLine("\n======== Part 3 ========");
        Random random1 = new Random(5);
        var input1 = Enumerable.Range(1, 100).Select(i => random1.Next() % 101).ToList();
        var output1 = Problem1.myFilter(input1);

        foreach (int i in output1) {
            Console.WriteLine(i);
        }

        Console.WriteLine("\n======== Part 4 ========");
        Random random2 = new Random(5);
        var input2 = Enumerable.Range(1, 100).Select(i => random2.Next() % 101).ToList();
        var output2 = Problem2.myFilter(input2);

        foreach (int i in output2) {
            Console.WriteLine(i);
        }

        Console.WriteLine("\n======== Part 5 ========");
        List<int> seq1 = Enumerable.Range(1, 15).ToList();
        List<int> seq2 = Enumerable.Range(1, 42).Where(i => i % 2 == 0).ToList();
        List<int> seq3 = Enumerable.Range(1, 21).Where(i => i % 2 != 0 && i != 1).ToList();
        List<int> seq4 = Enumerable.Range(1, 105).Where(i => i % 5 == 0).ToList();

        var output3 = Problem3.myFilter(seq1, seq2, seq3, seq4);

        if (output3.Count() == 0) {
            Console.WriteLine("List is empty");
        } else {
            foreach (int i in output3) {
                Console.WriteLine(i);
            }
        }
    }
}
