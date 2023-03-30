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

# Define the path to the directory and file to be created
path = "./" + data["Difficulty"].lower() + "/" + data["Problem Name"].lower().replace(" ", "_") + "/"
filename = "meta.json"

# Check if directory exists and create it if it doesn't
if not os.path.exists(path):
    os.makedirs(path)

# Write the data to JSON file
with open(os.path.join(path, filename), "w") as f:
    json.dump(data, f, indent=4)


# create an empty file called Solution.cpp
with open(os.path.join(path, "Solution.cpp"), "w") as file:
    pass
with open(os.path.join(path, "statement.html"), "w") as file:
    pass