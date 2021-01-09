<nav class="navbar navbar-expand-lg navbar-light bg-light">
    <a class="navbar-brand" href="<?= site_url("/finalproject/index/")?>">Home</a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav">
            <li class="nav-item">
                <a class="nav-link" href="<?= site_url("/finalproject/listing/")?>" tabindex="-1" aria-disabled="true">Movies</span></a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="<?= site_url("/finalproject/add/")?>" tabindex="-1" aria-disabled="true">Add</span></a>
            </li>
            <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Options</a>
                <div class="dropdown-menu" aria-labelledby="navbarDropdown">
                    <a class="dropdown-item" href="<?= site_url("/finalproject/change/")?>">Change Password</a>
                    <a class="dropdown-item" href="<?= site_url("/finalproject/changepfp/")?>">Change Profile Picture</a>
                    <a class="dropdown-item" href="<?= site_url("/finalproject/logout/")?>">Logout</a>
                </div>
            </li>
            <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Other Pages</a>
                <div class="dropdown-menu" aria-labelledby="navbarDropdown">
                    <a class="dropdown-item" href="<?= site_url("/finalproject/invalid/")?>">Invalid Form</a>
                    <a class="dropdown-item" href="<?= site_url("/finalproject/success/")?>">Success Page</a>
                </div>
            </li>
        </ul>
    </div>
</nav>