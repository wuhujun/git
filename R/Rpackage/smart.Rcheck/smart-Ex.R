pkgname <- "smart"
source(file.path(R.home("share"), "R", "examples-header.R"))
options(warn = 1)
library('smart')

assign(".oldSearch", search(), pos = 'CheckExEnv')
cleanEx()
nameEx("smart-package")
### * smart-package

flush(stderr()); flush(stdout())

### Name: smart-package
### Title: What the package does (short line) ~~ package title ~~
### Aliases: smart-package smart
### Keywords: package

### ** Examples

~~ simple examples of the most important functions ~~



cleanEx()
nameEx("smart")
### * smart

flush(stderr()); flush(stdout())

### Name: smart
### Title: smart
### Aliases: smart
### Keywords: ~kwd1 ~kwd2

### ** Examples

##---- Should be DIRECTLY executable !! ----
##-- ==>  Define data, use random,
##--	or do  help(data=index)  for the standard data sets.

## The function is currently defined as
function () 
{
    print("This is a test of make a R package !")
  }



cleanEx()
nameEx("smooth")
### * smooth

flush(stderr()); flush(stdout())

### Name: smooth
### Title: smooth
### Aliases: smooth
### Keywords: ~kwd1 ~kwd2

### ** Examples

##---- Should be DIRECTLY executable !! ----
##-- ==>  Define data, use random,
##--	or do  help(data=index)  for the standard data sets.

## The function is currently defined as
function () 
{
    print("The function is smooth the time series !")
  }



### * <FOOTER>
###
cat("Time elapsed: ", proc.time() - get("ptime", pos = 'CheckExEnv'),"\n")
grDevices::dev.off()
###
### Local variables: ***
### mode: outline-minor ***
### outline-regexp: "\\(> \\)?### [*]+" ***
### End: ***
quit('no')
