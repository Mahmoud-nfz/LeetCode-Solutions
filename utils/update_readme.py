import json
from utils.replace_between_tags import replace_between_tags
from colorama import init, Fore, Style

def update_readme(problems):
    readme_path = "README.md"
    with open(readme_path,"+r") as f:
        readme = f.read()
        # print(readme)
        content_to_write = "\n"
        for category in problems:
            content_to_write += f"## {category.replace('./','').upper()}\n"
            print(category)
            content_to_write += "| Problem | Solution | Difficulty | Tags |\n"
            content_to_write += "| ------- | -------- | ---------- | ---- |\n"
            if('Contest' not in category):
                for problem in problems[category]:
                    content_to_write += f"| [{problem['Problem Name']}]({problem['relative url']}) | [C++]({problem['relative url']}) | {problem['Difficulty']} | {problem['Tags']} |\n"
                content_to_write += "\n"
            else:
                for contest in problems[category]:
                    backslash = "\\"
                    content_to_write += f"| {contest.replace('./contest/','').replace(f'./contest{backslash}','')} | | | |\n"
                    for problem in problems[category][contest]:
                        content_to_write += f"| [{problem['Problem Name']}]({problem['relative url']}) | [C++]({problem['relative url']}) | {problem['Difficulty']} | {problem['Tags']} |\n"
                content_to_write += "\n"

        readme = replace_between_tags(readme, content_to_write,"<!-- PROBLEMS START -->","<!-- PROBLEMS END -->")
        
        with open(readme_path, "w") as f:
            f.write(readme)
            print(Fore.CYAN + f"Successfully updated {readme_path}" + Style.RESET_ALL)
    
    # # dump problems in temp.json file
    # with open("temp.json", "w") as f:
    #     json.dump(problems, f, indent=4)
