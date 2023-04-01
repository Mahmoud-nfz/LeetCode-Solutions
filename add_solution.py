import os
import json

# Define the data to be written to JSON file
data = {}
# {
#     "Problem Name" : "",
#     "Problem URL" : "",
#     "Tags" : [""],
#     "Difficulty" : "",
#     "Submission" : "",
#     "Runtime" : "",
#     "Memory" : "",
#     "Average Complexity" : "",
#     "Worst Complexity" : ""
# }
infos = ["Problem Name", "Problem URL", "Tags", "Difficulty", "Submission", "Runtime", "Memory", "Average Complexity", "Worst Complexity"]

for info in infos:
    print("Enter the " + info + ":")
    data[info] = input()

data["Tags"] = [s.strip() for s in data["Tags"].split(",")]
optimized = False

if(input("Create file for additional optimized solution? y/[N]: \n") == "y"):
    optimized = True
    data["Additional Optimized Solution"] = True
    data["Optimized Submission"] = input("Enter the number optimized solution submission URL :\n")

contestPath = ""
if(input("Is this a contest problem? y/[N]: \n") == "y"):
    data["Contest"] = True
    data["Contest Name"] = input("Enter the contest name (example : BiWeekly Contest 98) :\n")
    if not os.path.exists("./contest/" + data["Contest Name"].lower().replace(" ", "-")):
        data["Contest URL"] = input("Enter the contest URL :\n")
    contestPath = "./contest/" + data["Contest Name"].lower().replace(" ", "-") + "/"


# Define the path to the directory and file to be created
filename = "meta.json"
path = "./" + data["Difficulty"].lower() + "/" + data["Problem Name"].lower().replace(" ", "_") + "/"
if(data["Contest"]):
    path = contestPath + data["Problem Name"].lower().replace(" ", "_") + "/"
    # create meta.json in contest folder
    if not os.path.exists(contestPath):
        os.makedirs(contestPath)
        with open(os.path.join(contestPath, "contest.meta.json"), "w") as f:
            json.dump({
                "Contest Name" : data["Contest Name"],
                "Contest URL" : data["Contest URL"]
            }, f, indent=4)

# Check if directory exists and create it if it doesn't
if not os.path.exists(path):
    os.makedirs(path)

# Write the data to JSON file
with open(os.path.join(path, filename), "w") as f:
    json.dump(data, f, indent=4)


# create an empty file called Solution.cpp
with open(os.path.join(path, "Solution.cpp"), "w") as file:
    pass
if optimized:
    with open(os.path.join(path, "Solution.Optimized.cpp"), "w") as file:
        pass
with open(os.path.join(path, "statement.html"), "w") as file:
    pass