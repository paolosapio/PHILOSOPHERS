FROM ubuntu

RUN apt-get update && \
	apt-get install -y zsh build-essential curl git btop && \
	apt-get clean && \
	rm -rf /var/lib/apt/lists/*

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

RUN chsh -s $(which zsh)


CMD ["zsh"]
