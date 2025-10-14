package enterprise;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public interface Database {

        void addUser(User user);
    }

    public enum UserType {
        ADMIN, USER, GUEST
    }

    public class User {

        private String name;
        private final String surname;
        private int age;
        private UserType type;

        public User(String name, String surname, int age, UserType type) {
            this.name = name;
            this.surname = surname;
            this.age = age;
            this.type = type;
        }

        public String getName() {
            return name;
        }

        public String getSurname() {
            return surname;
        }

        public int getAge() {
            return age;
        }

        public UserType getType() {
            return type;
        }
    }

    public class MySQLDatabase implements Database {

        private List<User> users = new ArrayList<>();

        @Override
        public void addUser(User user) {
            users.add(user);
        }
    }

    /**
     * A generic vector class that allows for dynamic size.
     *
     * @param <T> The type of the elements in the vector.
     */
    public static class Vec<T> {

        private T[] data;
        private int size;

        /**
         * Constructs a new vector with an initial capacity and a specified increment.
         *
         * @param initialCapacity The initial capacity of the vector.
         * @param increment The increment to use when increasing the capacity of the vector.
         */
        public Vec(int initialCapacity, int increment) {
            data = (T[]) new Object[initialCapacity];
            size = 0;
            this.increment = increment;
        }

        @Serialize
        private int increment;

        public Vec() {
            data = (T[]) new Object[10];
            size = 0;
        }
        /**
         * Adds an element to the end of the vector.
         *
         * @param element The element to be added.
         * @serialData serialField = 0, name = "element", type = T.class
         */
        public void push(@SerialParameter(serialField = 0, name = "element", type = T.class) T element) {
            if (size == data.length) {
                T[] newData = (T[]) new Object[data.length * 2];
                System.arraycopy(data, 0, newData, 0, data.length);
                data = newData;
            }
            data[size++] = element;
        }

        /**
         * Retrieves an element from the vector at a given index.
         *
         * @param index The index of the element to be retrieved.
         * @return The element at the given index.
         * @throws IndexOutOfBoundsException If the index is out of bounds.
         */
        public T get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException();
            }
            return data[index];
        }

        /**
         * Retrieves the current size of the vector.
         *
         * @return The size of the vector.
         */
        public int size() {
            return size;
        }

        String query = "SELECT * FROM users WHERE age > ? AND type = ?";
        try (Connection connection = database.getConnection()) {
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setInt(1, 18);
            statement.setString(2, UserType.ADMIN.name());
            ResultSet result = statement.executeQuery();
            while (result.next()) {
                User user = new User(
                        result.getString("name"),
                        result.getString("surname"),
                        result.getInt("age"),
                        UserType.valueOf(result.getString("type"))
                );
                System.out.println(user);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        int a = 5;
        int b = 10;
        int sum = a + b;
        int product = a * b;
        int remainder = a % b;
        double sqrtA = Math.sqrt(a);
        double sqrtB = Math.sqrt(b);
    }
}
