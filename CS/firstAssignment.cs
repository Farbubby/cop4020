public class USFStudent {
    public void sayIt() {
        System.Console.WriteLine("Go Bulls!");
    }

    public void intro() {
        System.Console.WriteLine("I am a USF student.");
    }
}

public class UCFStudent {
    public void sayIt() {
        System.Console.WriteLine("Charge On!");
    }

    public void intro() {
        System.Console.WriteLine("I am a UCF student.");
    }
}

public class UFStudent {
    public void sayIt() {
        System.Console.WriteLine("Go Gators!");
    }

    public void intro() {
        System.Console.WriteLine("I am a UF student.");
    }
}

class Program {
    static void Main() {
        USFStudent usfStudent = new USFStudent();
        UCFStudent ucfStudent = new UCFStudent();
        UFStudent ufStudent = new UFStudent();

        usfStudent.sayIt();
        usfStudent.intro();

        Console.WriteLine();

        ucfStudent.sayIt();
        ucfStudent.intro();

        Console.WriteLine();

        ufStudent.sayIt();
        ufStudent.intro();
    }
}
