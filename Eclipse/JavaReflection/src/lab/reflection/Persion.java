package lab.reflection;

public abstract class Persion {
	protected String name;
	private int age;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public Persion(String name, int age) {
		setName(name);
		setAge(age);
	}

	public abstract void sayHello();
}
