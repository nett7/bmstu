# Industrial Development 6
## Software dev life cycle


### Models

- Cascade Models

Good for gov projects with fixed dev span and defined resources.
Heavily based on technical task.
- a. Waterfall Model

No return to previous dev step
- b. V-Shaped Model

Waterfall Model with additional marks for step connection.
There is a way to simplify acceptence step : delegate acceptence mechanism to acceptence tests

- Iterative Models
- a. Iterative and incremental model
Based on artifact accumulation that are used on next step of dev cycle
- b. Spiral Model
Based on accumulated exp and artifacts
- c. Agile
Based on Agile Manifesto

```
We follow these principles:

Our highest priority is to satisfy the customer
through early and continuous delivery
of valuable software.

Welcome changing requirements, even late in
development. Agile processes harness change for
the customer's competitive advantage.

Deliver working software frequently, from a
couple of weeks to a couple of months, with a
preference to the shorter timescale.

Business people and developers must work
together daily throughout the project.

Build projects around motivated individuals.
Give them the environment and support they need,
and trust them to get the job done.

The most efficient and effective method of
conveying information to and within a development
team is face-to-face conversation.

Working software is the primary measure of progress.

Agile processes promote sustainable development.
The sponsors, developers, and users should be able
to maintain a constant pace indefinitely.

Continuous attention to technical excellence
and good design enhances agility.

Simplicity--the art of maximizing the amount
of work not done--is essential.

The best architectures, requirements, and designs
emerge from self-organizing teams.

At regular intervals, the team reflects on how
to become more effective, then tunes and adjusts
its behavior accordingly.
```
- 1. XP

- - - i. Pair programming
- - - ii. ci
- - - iii. TDD - test driven dev
- - - iv. refactoring
- - - v. small releases
- - - vi. coding standards
- - - vii. collective code ownership (make code understandable for all)
- - - vii. KISS
- - - iix. DRY

- 2. Scrum
- - i. Sprint (Short time span for task planing)

- 3. Kanban

Based on boards. `backlog/in progress/peer review/testing/done`

#### History

1. SP - Structural Programming: based on C structures and functions '69
2. OOP '95
3. Scrum '95
4. Agile '05

### Issue Trackers : JIRA

`NOTE` `:` `Do Not Forget To Add Issue Tags To Commit`

Tasks:
1. Dev Tasks (Can be subdivided to smaller tasks)
2. Bugfix (Usually can not be subdivided; often bug can be already solved, watch issue trackers history; bugs can be unreproducible)
3. Self-defined task from user (Passage from testing to done can be shorter if CI is used)

`NOTE` : In `In Progress` board can be only up to 2 tasks. It incentivizes programmer to finish tasks.

