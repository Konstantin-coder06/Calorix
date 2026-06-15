// CalorixProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Calorix.h"
#include "Date.h"

int main()
{
    Calorix& calorix = Calorix::getInstance();

    while (true)
    {
        try
        {
            int choice;

            std::cout << "\n===== CALORIX =====\n";
            std::cout << "1. Register\n";
            std::cout << "2. Login\n";
            std::cout << "3. Logout\n";
            std::cout << "4. Admin menu\n";
            std::cout << "5. Trainee menu\n";
            std::cout << "6. Help\n";
            std::cout << "7. End\n";
            std::cout << "Choice: ";
            std::cin >> choice;

            if (choice == 1)
            {
                std::string username, password;
                int age;
                double weight, height;

                std::cout << "Username: ";
                std::cin >> username;

                std::cout << "Password: ";
                std::cin >> password;

                std::cout << "Age: ";
                std::cin >> age;

                std::cout << "Weight: ";
                std::cin >> weight;

                std::cout << "Height: ";
                std::cin >> height;

                

                calorix.registerUser(username, password, age,weight,height,true);

                std::cout << "Registered successfully.\n";
            }
            else if (choice == 2)
            {
                std::string username, password;

                std::cout << "Username: ";
                std::cin >> username;

                std::cout << "Password: ";
                std::cin >> password;

                calorix.login(username, password);

                std::cout << "Login successful.\n";
            }
            else if (choice == 3)
            {
                calorix.logout();
                std::cout << "Logged out.\n";
            }
            else if (choice == 4)
            {
                int adminChoice;

                std::cout << "\n===== ADMIN MENU =====\n";
                std::cout << "1. Add food\n";
                std::cout << "2. Add exercise\n";
                std::cout << "3. Update food\n";
                std::cout << "4. Block user\n";
                std::cout << "Choice: ";
                std::cin >> adminChoice;

                if (adminChoice == 1)
                {
                    std::string name;
                    double calories, protein, carbs, fat;

                    std::cout << "Food name: ";
                    std::cin >> name;

                    std::cout << "Calories per 100g: ";
                    std::cin >> calories;

                    std::cout << "Protein per 100g: ";
                    std::cin >> protein;

                    std::cout << "Carbs per 100g: ";
                    std::cin >> carbs;

                    std::cout << "Fat per 100g: ";
                    std::cin >> fat;

                    calorix.addFood(name, calories, protein, carbs, fat);

                    std::cout << "Food added.\n";
                }
                else if (adminChoice == 2)
                {
                    std::string name;
                    double caloriesBurned;

                    std::cout << "Exercise name: ";
                    std::cin >> name;

                    std::cout << "Calories burned per hour: ";
                    std::cin >> caloriesBurned;

                    calorix.addExercise(
                        name,
                        caloriesBurned,
                        MuscleGroup::Chest
                    );

                    std::cout << "Exercise added.\n";
                }
                else if (adminChoice == 3)
                {
                    std::string foodName;
                    double newCalories;

                    std::cout << "Food name: ";
                    std::cin >> foodName;

                    std::cout << "New calories: ";
                    std::cin >> newCalories;

                    calorix.updateFood(foodName, newCalories);

                    std::cout << "Food updated.\n";
                }
                else if (adminChoice == 4)
                {
                    std::string username;

                    std::cout << "Username to block: ";
                    std::cin >> username;

                    calorix.blockUser(username);

                    std::cout << "User blocked.\n";
                }
            }
            else if (choice == 5)
            {
                int traineeChoice;

                std::cout << "\n===== TRAINEE MENU =====\n";
                std::cout << "1. Log food\n";
                std::cout << "2. Log exercise\n";
                std::cout << "3. View daily summary\n";
                std::cout << "4. View progress\n";
                std::cout << "5. Calculate BMI\n";
                std::cout << "6. Calculate BMR\n";
                std::cout << "7. Add to favorites\n";
                std::cout << "8. View favorites\n";
                std::cout << "9. Generate workout plan\n";
                std::cout << "Choice: ";
                std::cin >> traineeChoice;

                if (traineeChoice == 1)
                {
                    std::string foodName;
                    double quantity;

                    std::cout << "Food name: ";
                    std::cin >> foodName;

                    std::cout << "Quantity grams: ";
                    std::cin >> quantity;

                    Date today(15, 6, 2026);

                    calorix.logFood(foodName, quantity, today);

                    std::cout << "Food logged.\n";
                }
                else if (traineeChoice == 2)
                {
                    std::string exerciseName;
                    double duration;

                    std::cout << "Exercise name: ";
                    std::cin >> exerciseName;

                    std::cout << "Duration minutes: ";
                    std::cin >> duration;

                    Date today(15, 6, 2026);

                    calorix.logExercise(exerciseName, duration, today);

                    std::cout << "Exercise logged.\n";
                }
                else if (traineeChoice == 3)
                {
                    calorix.viewDailySummary();
                }
                else if (traineeChoice == 4)
                {
                    calorix.viewProgress();
                }
                else if (traineeChoice == 5)
                {
                    calorix.calculateBMI();
                }
                else if (traineeChoice == 6)
                {
                    calorix.calculateBMR();
                }
                else if (traineeChoice == 7)
                {
                    std::string exerciseName;

                    std::cout << "Exercise name: ";
                    std::cin >> exerciseName;

                    calorix.addToFavorites(exerciseName);

                    std::cout << "Added to favorites.\n";
                }
                else if (traineeChoice == 8)
                {
                    calorix.viewFavorites();
                }
                else if (traineeChoice == 9)
                {
                    int duration;

                    std::cout << "Workout duration minutes: ";
                    std::cin >> duration;

                    calorix.generateWorkoutPlan(duration);
                }
            }
            else if (choice == 6)
            {
                calorix.help();
            }
            else if (choice == 7)
            {
                calorix.end();
                break;
            }
            else
            {
                std::cout << "Invalid choice.\n";
            }
        }
        catch (const std::exception& ex)
        {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }

    return 0;
}


