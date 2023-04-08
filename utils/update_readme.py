import json
import re
from colorama import init, Fore, Style

def update_readme(problems):
    readme_path = "README.md"
    with open(readme_path,"+r") as f:
        readme = f.read()
        content_to_write = ""
        for category in problems:
            content_to_write += f"## {category.replace('./','').upper()}\n"
            content_to_write += "| Problem | Solution | Difficulty | Tags |\n"
            content_to_write += "| ------- | -------- | ---------- | ---- |\n"
            if('Contest' not in category):
                for problem in problems[category]:
                    content_to_write += f"| [{problem['Problem Name']}]({problem['relative url']}) | [C++]({problem['relative url']}) | {problem['Difficulty']} | {problem['Tags']} |\n"
                content_to_write += "\n"
            else:
                for contest in problems[category]:
                    content_to_write += f"| {contest.replace('./contest/','')} | | | |\n"
                    for problem in problems[category][contest]:
                        content_to_write += f"| [{problem['Problem Name']}]({problem['relative url']}) | [C++]({problem['relative url']}) | {problem['Difficulty']} | {problem['Tags']} |\n"
                content_to_write += "\n"
        
        readme = re.sub(r"<!-- PROBLEMS START -->.*<!-- PROBLEMS END -->", f"<!-- PROBLEMS START -->\n{content_to_write}<!-- PROBLEMS END -->", readme, flags=re.DOTALL)
        # f.write(readme)
        with open(readme_path, "w") as f:
            f.write(readme)
            print(Fore.CYAN + f"Successfully updated {readme_path}" + Style.RESET_ALL)
    
    # # dump problems in temp.json file
    # with open("temp.json", "w") as f:
    #     json.dump(problems, f, indent=4)
