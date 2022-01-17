$PROJECT_NAME = "Isolation"
$PROJECT_PATH = "D:\Projects\C++\Isolation\project"
$BUILD_PATH = "${PROJECT_PATH}\..\out"
$BIN_PATH = "${PROJECT_PATH}\..\out\bin\debug"

function configure {
    Write-Host "configuring...";
    cmake -S . -B $BUILD_PATH;
    if($?) { Write-Host "configuring completed." -ForegroundColor Green; };
}

function build {
    Write-Host "building...";
    cmake --build $BUILD_PATH;
    if($?) { Write-Host "build completed." -ForegroundColor Green; };
}

function run {
    Write-Host "running...";
    Invoke-Expression "${BIN_PATH}\${PROJECT_NAME}-d.exe";
}

function buildandrun {
    build;
    if($?) { run; };
}

function cleanall {
    Write-Host "Cleaning...";
    $null = rm $BUILD_PATH\* -Force -Recurse;
    Write-Host "Cleaning is completed." -ForegroundColor Green;
}

while(1)
{
    Write-Host "(1)configure, (2)build, (3)build and run, (4)run, (5)clean all, (q)exit";
    $ans = Read-Host;
    switch($ans)
    {
        1 { configure; Break }
        2 { build; Break}
        3 { buildandrun; Break }
        4 { run; Break }
        5 { cleanall; Break }
        'q' { Exit; Break }
        defalut { Break }

    }
}