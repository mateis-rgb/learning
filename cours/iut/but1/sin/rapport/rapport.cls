\LoadClass[a4paper,12pt]{article} % Classe du document

%--------------------- Packages ------------------------

\RequirePackage[french]{babel} % Language of the document
\RequirePackage[utf8]{inputenc}
\RequirePackage[section]{placeins}
\RequirePackage[T1]{fontenc}
\RequirePackage{lmodern}
\RequirePackage{mathtools}
\RequirePackage{siunitx}
\RequirePackage{float}
\RequirePackage{graphicx}
\RequirePackage[justification=centering]{caption}
\RequirePackage{subcaption}
\RequirePackage{wallpaper}
\RequirePackage{nomencl}
\RequirePackage{fancyhdr}
\RequirePackage{url}
\RequirePackage[hidelinks]{hyperref}
\RequirePackage[left=2.5cm,right=2.5cm,top=2cm,bottom=3.5cm]{geometry}

%-------------------- Report information ----------------------

\newcommand{\subject}[1]{\renewcommand{\subject}{#1}}
\newcommand{\topic}[1]{\renewcommand{\topic}{#1}}
\newcommand{\ttitle}[1]{\renewcommand{\ttitle}{#1}}
\newcommand{\professor}[1]{\renewcommand{\professor}{#1}}
\newcommand{\students}[1]{\renewcommand{\students}{#1}}
\newcommand{\logo}[1]{\renewcommand{\logo}{#1}}
\newcommand{\uni}[1]{\renewcommand{\uni}{#1}}
\newcommand{\name}[1]{\renewcommand{\name}{#1}}

\newcommand{\buildmargins}{
\makenomenclature
\pagestyle{fancy}
\fancyheadoffset{1cm}
\setlength{\headheight}{2cm}
\lhead{\includegraphics[scale=0.5]{src/ua_iut_h_noir_ecran.png}}
\rhead{\nouppercase{\leftmark}}
\rfoot{\thepage}
\cfoot{\textbf{\topic}}
\lfoot{\subject}
}

\newcommand{\buildcover}{
\begin{titlepage}

	\centering
	\includegraphics[width=0.75\textwidth]{\logo}\par\vspace{1cm} % Logo insertion on the front cover
	{\scshape\LARGE \uni \par} % name of university
	\vspace{1.5cm}
    \rule{\linewidth}{0.2 mm} \\[0.4 cm]
	{\huge\bfseries \ttitle \par} \
    \rule{\linewidth}{0.2 mm} \\[1.5 cm]
	\vspace{1cm}
    
	\begin{minipage}{0.5\textwidth}
		\begin{flushleft} \large
		\emph{\textbf{Étudiants :}}\\
        \students\\ % each student should be added using this command
		\end{flushleft}
	\end{minipage}
	~
	\begin{minipage}{0.4\textwidth}
		\begin{flushright} \large
            \emph{\textbf{Professeurs :}}\\
		 \professor \\
		\end{flushright}
	\end{minipage}\\[4cm]
    
	\vfill
	{\large \today\par} % Date

\end{titlepage}
}

\newcommand{\toc}{
\tableofcontents
\newpage
}

\newcommand{\insererfigure}[4]{
\begin{figure}[ht]
\centering
\includegraphics[height=#2]{#1}
\caption{#3}
\label{fig: #4}
\end{figure}
}



