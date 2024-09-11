# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

alias la="ls -la";
alias neofetch="~/.bin/neofetch";
alias py="python3";
alias pip="python3 -m pip";
alias php="/Applications/XAMPP/xamppfiles/bin/php/";
alias composer="php ~/.bin/composer";
alias openvpn="echo /usr/local/Cellar/openvpn/2.6.7/sbin/openvpn";
alias jwttool="python3 ~/.bin/jwt_tool/jwt_tool.py";
alias hash-identifier="python3 ~/.bin/hash-identifier/hash-id.py";
alias spiderfoot_cli="python3 ~/.bin/spiderfoot/sfcli.py";
alias spiderfoot="python3 ~/.bin/spiderfoot/sf.py";
alias gcc="gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin";
alias g++="g++ -Wall";
alias holmes="python3 ~/.bin/Mr.Holmes/MrHolmes.py";
alias adb="/Users/mat/.bin/platform-tools/adb";
alias fastboot="/Users/mat/.bin/platform-tools/fastboot";

source ~/.bin/zsh-autocomplete/zsh-autocomplete.plugin.zsh
source $(brew --prefix)/share/zsh-autosuggestions/zsh-autosuggestions.zsh
source $(brew --prefix)/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

# Created by `pipx` on 2023-09-27 08:50:43
export PATH="$PATH:/Users/mat/.local/bin"


export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

PATH=~/.console-ninja/.bin:$PATH
source /usr/local/share/powerlevel10k/powerlevel10k.zsh-theme
