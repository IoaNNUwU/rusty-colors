using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Enterprise
{
    public enum UserType
    {
        Admin,
        User
    }

    public interface IUserRepository
    {
        /// <summary>
        /// Adds a user to the repository.
        /// </summary>
        /// <param name="user">The user to add.</param>
        void AddUser(User user);

        /// <summary>
        /// Gets all users from the repository.
        /// </summary>
        /// <returns>A list of users.</returns>
        List<User> GetAllUsers();
    }

    /// <summary>
    /// Class to represent a user.
    /// </summary>
    public class User
    {
        /// <summary>
        /// Gets or sets the user's ID.
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        /// Gets or sets the user's name.
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Gets or sets the user's email.
        /// </summary>
        public string Email { get; set; }
        public UserType Type { get; set; }
    }

    public class UserRepository : IUserRepository
    {
        private readonly List<User> _users;

        public UserRepository()
        {
            _users = new List<User>();
        }

        public void AddUser(User user)
        {
            _users.Add(user);
        }

        public List<User> GetAllUsers()
        {
            return _users;
        }
    }

    public class Program
    {
        static void Main(string[] args)
        {
            var userRepository = new UserRepository();

            var user = new User
            {
                Name = "John Doe",
                Email = "john@example.com",
                Type = UserType.Admin
            };

        /// Class to contain the main application entry point.
        /// </summary>
        userRepository.AddUser(user);

        /// <summary>
        /// The main application entry point.
        /// </summary>
        /// <param name="args">The command line arguments.</param>
            var users = userRepository.GetAllUsers();

            foreach (var userItem in users)
            {
                Console.WriteLine($"User: {userItem.Name} ({userItem.Type})");
            }
        }
    }
}

            Console.WriteLine("Example of using numbers:");
            int number = 42;
            float floatNumber = 3.14f;
            double doubleNumber = 3.14159;
            decimal decimalNumber = 3.14159m;

            bool boolean = true;
            byte byteNumber = 42;
            sbyte signedByteNumber = -42;
            short shortNumber = 123;
            ushort unsignedShortNumber = 123;
            int integerValue = 123;
            uint unsignedInteger = 123;
            long longNumber = 123;
            ulong unsignedLongNumber = 123;
            char character = 'a';
            float floatNumber = 3.14f;
            double doubleNumber = 3.14159;
            decimal decimalNumber = 3.14159m;



            Console.WriteLine("Example of using math:");
            double radius = 5;
            double area = Math.PI * Math.Pow(radius, 2);
            double circumference = 2 * Math.PI * radius;
            Console.WriteLine($"Area of circle with radius {radius}: {area}");
            Console.WriteLine($"Circumference of circle with radius {radius}: {circumference}");

            
            
