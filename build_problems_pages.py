import os
import sys
import json
from colorama import init, Fore, Style
from utils.update_readme import update_readme
from utils.remove_comments import remove_comments

template_path = "Problem.template.md"
with open(template_path) as f:
    problem_template = f.read()

base_dirs = ["./easy", "./medium", "./hard"]

list_dirs = [os.listdir(base_dir) for base_dir in base_dirs if os.path.isdir(base_dir)]

dirs = [(os.path.join(base_dir, directory),base_dir) for base_dir, directory_list in zip(base_dirs, list_dirs) for directory in directory_list]

flags = {
    "success" : 0,
    "error" : 0,
    "warning": 0
}

# add all folders in all the folders in './contest' to dirs
contest_dirs = [os.path.join("./contest", directory) for directory in os.listdir("./contest") if os.path.isdir(os.path.join("./contest", directory))]
for contest_dir in contest_dirs:
    dirs += [(os.path.join(contest_dir, directory),contest_dir) for directory in os.listdir(contest_dir) if os.path.isdir(os.path.join(contest_dir, directory))]

problems = {}

for directory, base_dir in dirs:
    if not os.path.isdir(directory):
        continue
    
    meta_path = os.path.join(directory, "meta.json")
    if not os.path.exists(meta_path):
        print(Fore.RED + f"Error: meta.json not found in {directory}" + Style.RESET_ALL)
        flags["error"] += 1
        continue
    
    with open(meta_path) as f:
        meta = json.load(f)
    
    statement_path = os.path.join(directory, "statement.html")
    statement = ""
    if not os.path.exists(statement_path):
        print(Fore.YELLOW + f"Warning: statement.html not found in {directory}" + Style.RESET_ALL)
        flags["warning"] += 1
    else:
        with open(statement_path) as f:
            statement = f.read()
    
    solution_path = os.path.join(directory, "Solution.cpp")
    if not os.path.exists(solution_path):
        print(Fore.RED + f"Warning: Solution.cpp not found in {directory}" + Style.RESET_ALL)
        flags["error"] += 1
        continue
    
    with open(solution_path) as f:
        solution_explained = f.read()
        solution_raw = remove_comments(solution_explained)

    template = problem_template
    mappings = {
        "{problem.url}" : "Problem URL",
        "{problem.title}" : "Problem Name",
        "{problem.difficulty}" : "Difficulty",
        "{problem.tags}" : "Tags",
        "{problem.tutorials}" : "Tutorials",
    }
    meta["Tags"] = ", ".join(meta["Tags"])
    meta["Tutorials"] = ""
    for placeholder, key in mappings.items():
        template = template.replace(placeholder, meta[key])
    template = template.replace("{problem.statement}", statement)
    template = template.replace("{problem.solutions.cpp.explained}", solution_explained)
    template = template.replace("{problem.solutions.cpp.raw}", solution_raw)
    
    filename = os.path.join(directory, os.path.basename(directory) + ".md")
    meta["relative url"] = filename.replace("\\", "/")
    with open(filename, "w") as f:
        f.write(template)
    
    print(Fore.GREEN + f"Successfully generated {filename}" + Style.RESET_ALL)
    flags["success"] += 1

    if('contest' in base_dir):
        if 'Contests' not in problems:
            problems['Contests'] = {base_dir: [meta]}
        elif base_dir not in problems['Contests']:
            problems['Contests'][base_dir] = [meta]
        else:
            problems['Contests'][base_dir].append(meta)
    elif(base_dir not in problems):
        problems[base_dir] = [meta]
    else:
        problems[base_dir].append(meta)    

print("Summary:\nPages generated with ",end="")
print(
    Fore.GREEN + f"{flags['success']}" + Style.RESET_ALL + " Successful "
    + Fore.RED + f"{flags['error']}" + Style.RESET_ALL + " Errors "
    + Fore.YELLOW + f"{flags['warning']}" + Style.RESET_ALL + " Warnings "
)

update_readme(problems)

# if some condition is not met, exit with a non-zero exit code
if flags["error"] > 0:
    print("Commit failed: There are some errors")
    sys.exit(1)

# print(problems)
sys.exit(0)

