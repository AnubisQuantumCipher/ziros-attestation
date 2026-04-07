# ZirOS System: Listening Report

## A listening-first synthesis of what ZirOS is, why it exists, and what the developer experience is meant to be

This report is written for listening.

It is not a sales page, and it is not a personal opinion essay. It is a long-form spoken-style synthesis of the public ZirOS attestation repository as it exists now. The goal is simple. If someone listens to this report from start to finish, they should come away with a clear answer to three questions.

First, what is ZirOS.

Second, why does ZirOS exist.

Third, what is the developer experience supposed to be when someone actually tries to use it.

This report stays inside the public evidence boundary. It uses the public README, the public attestation JSON, the public theorem ledger summary, the public SDK surface, the public proof-server documentation, the public Midnight deployment material, and the other public position documents in this repository. It does not pretend to know more than the public evidence supports, and it does not treat the private implementation as if it were public.

That matters because ZirOS is not published as a source-open framework. It is published as a source-private system with a public evidence boundary. Any honest explanation of ZirOS has to begin there.

The current public surface says the following. ZirOS presents itself as a zero-knowledge operating system. The public repository states that the system spans 290,000 lines of Rust across 30 workspace crates, 9 proving backends, 7 finite fields, 7 circuit frontends, 63 Metal GPU shaders with 50 kernel entrypoints, and 169 mechanized ledger rows with 0 pending rows. Of those, the public headline count is 160 implementation-bound rows, while 9 protocol rows are disclosed separately as explicit hypothesis-carried theorem rows in the public protocol registry. The published attestation states that 24 out of 24 public conformance tests passed across the currently attested backend lanes. The public repository also documents a Midnight-compatible proof-server surface and five live Midnight preprod contract deployments.

Those are the facts this report starts from.

What follows is not a compressed changelog. It is a system explanation meant to be heard in sequence.

## 1. The simplest way to say what ZirOS is

The simplest accurate sentence is this: ZirOS is a system layer that sits between a developer's intent and the cryptographic machinery required to prove that intent.

That sentence is more useful than calling ZirOS a library, because the word library is too small. A library suggests a set of functions that a developer imports, calls, and understands more or less directly. ZirOS is described in the public repository as something broader. It is described as owning the path from a statement, to a circuit or proving program, to witness generation, to proof construction, to verification, to export, to deployment, and to attestation.

That is why the repository uses the phrase zero-knowledge operating system.

The important part of that phrase is not branding. The important part is the implied system boundary. When something is described as an operating system, the claim is that it is not just one tool among many. The claim is that it coordinates multiple layers beneath the application, abstracts away low-level machinery, and gives developers a stable surface from which they can build higher-level work.

In public terms, ZirOS says that it does this for zero-knowledge proving.

The repository does not present ZirOS as only a backend. It does not present ZirOS as only a frontend. It does not present ZirOS as only a proof server, or only an SDK, or only a command-line tool. Instead, it presents a connected system with several layers that are meant to work together.

There is a circuit authoring and import layer. There is a proving layer with multiple documented backends. There is a verification and export layer. There is a GPU acceleration layer on Apple Metal. There is an attestation and integrity layer. There is a public SDK surface. There is a command surface through the `zkf` binary. There is a public proof-server wire contract. There is a Midnight deployment surface. And there is an explicit claim that the whole thing is designed to support agentic operation by Claude Code or Codex.

If someone asks what ZirOS is in one sentence, the answer is that it is an attempt to turn zero-knowledge proving from a collection of specialist components into an operating surface.

If someone asks what ZirOS is in two sentences, the answer becomes slightly more precise. ZirOS is a system that tries to own the full proof workflow instead of leaving the developer to assemble the workflow by hand. The public repository exists to show evidence that this system exists and works, while keeping the private implementation source out of public view.

That second sentence is essential. Without it, a listener might think ZirOS is just another public proving framework with unusually strong documentation. That is not what the public repo says. The public repo says something narrower and more explicit: the system exists, the public evidence is published, the implementation remains private.

## 2. Why ZirOS exists at all

To explain why ZirOS exists, it helps to describe the problem it is trying to solve.

Traditional zero-knowledge development is fragmented. A developer often has to move between several mental models and several tools. They have to decide how to represent a statement. They have to understand constraints or intermediate representations. They have to generate witnesses correctly. They have to choose a backend. They have to understand what proof size, proof assumptions, and setup requirements come with that backend. They have to understand verification. If they need on-chain verification, they have to understand export. If they need privacy with selective disclosure, they have to design what is public, what is private, and what can be revealed under policy. If they need deployment on a specific chain, they have to understand that chain's integration points. If they need performance on real hardware, they have to deal with memory and acceleration. If they need reliability, they have to deal with testing, health checks, and operational discipline.

In many workflows, those concerns are scattered across different crates, different binaries, different documents, and different teams.

The public ZirOS framing suggests that the system exists because that fragmentation is too high a burden for the kind of products it wants to enable.

The repository does not frame the problem as academic circuit experimentation. It frames the problem as production subsystem development. That distinction matters. A subsystem is not just a proof. A subsystem includes domain logic, proving logic, public outputs, private witnesses, policy boundaries, deployment surfaces, and operational behavior. In the public ZirOS vocabulary, the developer is supposed to own the subsystem, while ZirOS owns the operating system beneath it.

That is a strong claim about why the system exists.

It exists because a proof by itself is not enough. A proof has to live inside an application context. It has to work under real performance constraints. It has to fit an integrity and attestation story. It has to fit deployment. It has to fit policy. It has to fit the way developers actually work. And, in the ZirOS framing, it increasingly has to fit the way AI coding agents work.

This is where the "why" of ZirOS becomes clearer.

ZirOS exists because the system is trying to collapse several separate burdens into one managed surface:

- proof authoring burden
- backend-selection burden
- witness-management burden
- verification burden
- export and deployment burden
- privacy-policy burden
- performance and acceleration burden
- attestation and integrity burden
- agent-automation burden

That does not mean ZirOS claims to solve all of these perfectly. It means the public story says those burdens belong in one operating layer rather than in the head of every application developer.

There is another reason ZirOS exists, and it comes from the public repository design itself.

The repository is evidence-first. That means the public release model is not centered on publishing implementation source. It is centered on publishing proof of integrity, proof of verification coverage, proof of conformance, and proof of deployment surfaces. That tells a listener something about the system's purpose. ZirOS is not only trying to make proof systems easier to use. It is also trying to make a source-private proving system legible and auditable enough that people can reason about it without seeing the core implementation.

So the "why" has two layers.

The first layer is technical. ZirOS exists to integrate a fragmented zero-knowledge workflow into a single system surface.

The second layer is publication and trust. ZirOS exists in a form where the core stays private, so a public attestation repository exists to make that private core externally legible.

If you leave out either layer, you miss the point of the project.

## 3. Why the term "operating system" matters

Many technical systems use large labels casually. The public ZirOS material does not read that way. The phrase operating system is doing real work.

It signals that the project is not describing a narrow proving library. It is describing a layer that standardizes the path between what a developer wants and what the proof machinery requires.

There are several implications packed into that.

The first implication is workflow ownership. An operating system owns the workflow beneath the application. In the ZirOS description, that means it is not enough to provide proof primitives. The system must also coordinate compilation, witness generation, proving, verification, export, hardware acceleration, and operational checks.

The second implication is application separation. An operating system is distinct from the app built on top of it. The public ZirOS repository is explicit about this. The developer-owned surface includes app logic, contracts, domain model, UI, and product license. The ZirOS-owned surface includes proving internals, GPU kernels, runtime scheduler, and the private engine implementation. This is a genuine operating-system-style boundary. The developer owns the application. ZirOS owns the kernel beneath it.

The third implication is infrastructure-level persistence. Libraries come and go inside an app. Operating systems define the environment in which the app runs. ZirOS uses that framing to say that proving is not an optional helper. It is the infrastructure layer that the subsystem depends on.

The fourth implication is abstraction. Developers should not need to manually reason about every lower-level detail for every job. That does not mean the details disappear. It means the details are mediated through a stable surface. The public repo points to several of those surfaces: the `zkf` CLI, the published SDK, the proof-server endpoints, the public constraint taxonomy, the public example circuit, and the machine-readable JSON outputs.

The fifth implication is policy. Operating systems define boundaries and failure modes. ZirOS leans into that language by repeatedly emphasizing fail-closed behavior, attestation, verification coverage, and explicit publication boundaries. It does not only say that proofs work. It says that the system is designed to fail in a disciplined way rather than hide uncertainty behind silent behavior.

Taken together, this explains why the term operating system is not ornamental in the public material.

It is a claim about scope.

It is a claim about ownership.

It is a claim about abstraction.

It is a claim about operational discipline.

And it is a claim about how the developer is supposed to interact with the system.

If a listener keeps that in mind, the rest of the public repository becomes easier to understand.

## 4. The public repository is part of the system, not just documentation about the system

One of the most important things to understand about ZirOS is that the public attestation repository is not only explanatory. It is operational.

This is unusual enough that it deserves slow explanation.

In many projects, the public repository is either the source itself or a thin wrapper around the source. Here, the public repository is intentionally source-free. It publishes machine-verifiable evidence, interface-level architecture, theorem metadata, conformance results, binary hashes, deployment manifests, and position documents about boundaries and coverage. It does not publish the private proving engine. It does not publish the private scheduler. It does not publish the private GPU kernel sources. It does not publish build scripts or Cargo manifests for the core.

At first glance, someone might hear that and reduce it to a negative statement: the source is not public.

But the repository is making a stronger positive claim than that.

It is saying that public trust in this system is supposed to be built through evidence surfaces rather than through direct source distribution.

That makes the public repo part of the system itself.

The attestation JSON is not just reading material. It is a published evidence object.

The theorem ledger summary is not just explanation. It is a statement of current mechanized coverage.

The conformance results are not just examples. They are the public proof that the currently attested lanes passed their published checks.

The binary manifest is not just a checksum list. It is the public integrity boundary around the shipped artifacts.

The proof-server endpoint documentation is not just a note. It is the public wire contract for a compatible server surface.

The Midnight deployment material is not just narrative. It is the public evidence that a specific subsystem surface has been deployed to Midnight preprod.

Even the boundary and coverage position papers are part of the system, because they define what the repository is willing to claim and what it refuses to claim.

This gives ZirOS a very specific publication model.

The public repo is designed to answer these questions:

- What is the system claiming exists right now?
- What evidence is published for that claim?
- Which parts are mechanized?
- Which parts are operational?
- Which parts are bounded but not theorem-level?
- Which parts are documented but not fully publicly attested?
- What remains private?

That is why the public repo cannot be treated as optional prose around a private core. It is the public trust surface for that private core.

Once that is understood, the existence of multiple long-form reports also makes sense. Reports are not decoration. They help bridge the gap between machine-verifiable artifacts and human understanding. A listener cannot absorb a full repository by hearing only filenames and counts. A report turns the evidence surfaces into a coherent spoken model.

That is what this report is trying to do.

## 5. What the public evidence says the system contains

If we stay at a high level, the public repository says ZirOS contains six major kinds of capability.

The first is proof generation capability.

The public repo describes nine proving backends. It does not say that all nine are equally exposed in the current public conformance set, and that distinction matters. But it does say that ZirOS is not tied to one proof lane. The public description includes transparent and trusted-setup lanes, classical and post-quantum surfaces, and a wrapper lane that combines a post-quantum inner proof with a classical outer proof for specific export goals.

The second is circuit or program ingress capability.

The public repo describes seven frontends or import surfaces. That means the system is presented not as a one-language proving engine, but as a system that can ingest multiple surface forms and route them into one proving pipeline. This matters for developer experience because it reduces the need for every subsystem to begin from the same internal format.

The third is hardware acceleration capability.

The public repository discloses a Metal GPU surface with 63 shader sources and 50 kernel entrypoints, plus a list of accelerators and pipeline-related counts. That tells a listener that ZirOS is not designed only for abstract proof generation. It is designed with real hardware execution in mind, particularly on Apple Silicon.

The fourth is integrity and attestation capability.

The repository emphasizes ML-DSA-87 signatures, binary hashes, and published evidence packages. This means ZirOS is not only trying to prove statements inside circuits. It is also trying to prove the integrity of the release and operational surface around those circuits.

The fifth is deployment and interoperability capability.

This includes Solidity verifier export, the public proof-server surface, and Midnight contract deployment evidence. In other words, ZirOS is not described as a system where proofs end in a file on disk. The public story says proofs can be exported, verified, deployed, and integrated into external surfaces.

The sixth is agentic control capability.

The repository is explicit that ZirOS is designed for operation by Claude Code and Codex. The claims here are not mystical. They are operational. The system exposes commands, structured output, and workflows that an agent can drive. The repository even names agent types such as proving agent, testing agent, healing agent, blueprint executor, and daemon agent.

If you put those six capability groups together, a listener gets a clearer picture of what ZirOS is trying to be.

It is not a system that focuses only on proving theory.

It is not a system that focuses only on chain deployment.

It is not a system that focuses only on GPU performance.

It is not a system that focuses only on developer ergonomics.

It is trying to combine all of those into a single operating surface.

That is why the public counts are so wide-ranging. The count of backends matters because it shows breadth of proof lanes. The count of frontends matters because it shows breadth of ingress. The count of shaders matters because it shows hardware depth. The count of theorems matters because it shows formal assurance. The count of Midnight contracts matters because it shows live deployment evidence. The conformance count matters because it shows current published verification behavior.

These are not random bragging numbers. They are meant to show that the system has multiple layers, and that public evidence exists for each layer.

## 6. What the public evidence says the system does not contain

An honest listening report also has to explain the absences.

The public ZirOS repository is explicit about what it does not contain, and that explicitness is one of the more important parts of the whole publication strategy.

It does not contain the private implementation source for ZirOS core.

It does not contain the private GPU shader source files in the way a normal source repository would.

It does not contain the private scheduler internals.

It does not contain the private swarm implementation source.

It does not contain proof-construction source.

It does not contain key material, private wallets, or private operational credentials.

It does not contain the full build system for the private core.

And it does not pretend otherwise.

That has several consequences.

The first consequence is that a third party cannot perform a full public line-by-line source audit of the private engine from this repository alone. The public repo simply does not offer that.

The second consequence is that the trust model has to be evidence-driven rather than source-driven. A listener has to evaluate the repository by asking what is attested, what is mechanized, what is published, and what is still private.

The third consequence is that the repository has to be unusually disciplined about not overstating what its public evidence proves. This is why the distinction between documented backends and publicly conformance-attested backends matters. It is why the distinction between deployed subsystem contracts and not-yet-publicly-deployed attestation contracts matters. It is why the distinction between mechanized and operational controls matters.

The fourth consequence is that long-form explanation matters more than usual. If a source-private system only published numbers and badges, the result would be under-specified. The repository therefore needs narrative material that tells people what the system is, what the evidence means, and where the limits are.

This also explains why the public position documents are as important as the counts. They tell a listener how to interpret the published evidence without assuming more than the evidence shows.

So when someone asks what ZirOS does not contain, the answer is not just "the code is private." The fuller answer is this: the repository withholds the private implementation and substitutes a published evidence boundary in its place. That substitution is not complete equivalence. It is a different trust surface. The whole public repo is arranged around making that different trust surface coherent.

## 7. Why the evidence-first model exists

It is worth pausing on this, because it goes to the heart of why ZirOS is structured the way it is.

The public repository suggests that ZirOS exists in a world where there is value in making a system externally legible without making the implementation fully public. Whether someone agrees with that strategy or not is a separate question. The important point is that the repo is unusually direct about the strategy itself.

Why would a system do that.

The public answer appears to be that source disclosure and trust are not treated as identical. Instead, ZirOS tries to build trust through a combination of theorem metadata, conformance publication, integrity manifests, deployment evidence, interface disclosure, and explicit statements about what is not yet covered.

That model exists for at least four reasons.

First, it protects the private implementation boundary.

Second, it still gives developers and outsiders a way to inspect the system's public claims.

Third, it allows the project to publish an evidence trail that can be updated over time, rather than depending only on one-time claims.

Fourth, it creates a public operator contract. The system is saying, in effect, "This is what we are willing to expose, this is how we describe it, this is how you can verify what we publish, and this is what remains behind the boundary."

For listening purposes, the important thing is not to over-romanticize this model. It is not magic. It does not remove all trust. It relocates trust.

A listener should hear the model this way.

Instead of trusting an open source codebase because it is open, you are being asked to trust a private system based on published evidence, published formal coverage, published interface boundaries, published deployment artifacts, and published integrity data.

That is a narrower form of trust than source transparency.

It is also a more concrete form of trust than simple marketing language.

The public ZirOS repository seems designed to make that trade explicit rather than hide it.

That is part of why the system exists the way it does. The evidence-first release model is not an afterthought. It is one of the defining choices of the whole public surface.

## 8. Why Midnight matters in the public ZirOS story

Midnight matters because it gives the public ZirOS story a concrete deployment environment where privacy, selective disclosure, and proof infrastructure all meet.

If ZirOS only published theorem counts and benchmark-style claims, a listener might understand it as a broad proving platform but not as a deployed application surface. Midnight changes that.

The public Midnight story has three parts.

The first part is interface compatibility.

The proof-server endpoint specification publishes a Midnight-compatible server surface with endpoints such as `/prove`, `/prove-tx`, `/check`, `/ready`, `/health`, `/version`, and related parameter or proof-version routes. That is important because it shows the system is not speaking about Midnight only in the abstract. It is publishing a wire contract.

The second part is live subsystem evidence.

The repository publishes five Midnight preprod transactions for contracts associated with the Sovereign Economic Defense subsystem surface. Those transaction links are not theoretical. They are chain-level artifacts. They show that a selective-disclosure-style application surface has actually been taken through deployment to Midnight preprod.

The third part is attestation boundary honesty.

The public Midnight material also states that certain attestation contracts are compiled and locally proven but not yet publicly deployed, with an explanation tied to chain stabilization after runtime changes. That matters because it tells the listener the repo is not flattening all Midnight activity into one undifferentiated claim. It is distinguishing what is live, what is locally proven, and what is still pending public deployment.

Why does this matter for the meaning of ZirOS.

Because Midnight is where the system's different promises come together.

Selective disclosure is not only a circuit property. It is also a product property and a chain-integration property.

Proof-server compatibility is not only a backend issue. It is also an operational contract.

Contract deployment is not only a proof issue. It is also a public evidence issue.

And the notion that regulators can see compliance bits while members keep private data private is not only privacy language. It is a statement about how the subsystem is supposed to behave under governance and disclosure constraints.

For listening purposes, it is helpful to say this plainly.

Midnight matters in the ZirOS story because it is the clearest public place where the system stops being only a proof engine and becomes a deployable privacy infrastructure surface.

## 9. What selective disclosure means in this system

Selective disclosure is one of the recurring ideas in the public ZirOS material, especially around Midnight.

The phrase can sound abstract, so it helps to unpack it in simple terms.

Selective disclosure means that the system is not trying to choose between two extremes: total transparency or total secrecy.

Instead, it is trying to make a narrower claim. A proof or contract can reveal the limited public facts required for policy, compliance, or verification, while withholding the underlying private data that produced those facts.

In public ZirOS terms, this is why subsystem examples talk about regulators seeing compliance bits while members keep their privacy.

That sentence is easy to hear too quickly. It contains several design assumptions.

One assumption is that the public facts worth revealing can be separated from the private facts worth protecting.

A second assumption is that the proof system can enforce that separation rather than relying only on social promises.

A third assumption is that the contract and application surface can preserve that separation during deployment and operation.

A fourth assumption is that developers need tools that make building this kind of split practical.

That last assumption is one of the main reasons ZirOS exists. Selective disclosure is much harder to ship if every application developer has to hand-assemble the proving, witness, policy, export, and deployment path themselves.

The public Midnight examples show the system trying to package this in a more application-oriented way. Instead of saying only "here is a proof primitive," the system says, in effect, "here is a subsystem surface in which public claims and private data are separated by design."

This also ties back to the developer experience.

The value of selective disclosure is not only that it can exist in theory. The value is that a developer can describe what must be proven, what must remain private, what can be disclosed, and then have the system produce the necessary proving and contract surfaces.

The public repo does not publish every internal step of that pipeline. But it does document enough of the system's intended behavior that this model becomes intelligible.

For a listener, the short version is this.

Selective disclosure is one of the clearest reasons ZirOS is not presented as a generic proving library. The system is trying to help developers build products where proof logic, contract logic, privacy policy, and disclosure policy all stay aligned.

## 10. The developer experience in plain language

A listening-first report needs to slow down the developer experience and explain it as an actual sequence.

In the public ZirOS model, the developer experience is not supposed to begin with low-level proving internals. It is supposed to begin with the thing the developer wants to prove.

That is the first key point.

The second key point is that the developer is not expected to own the proving engine. The developer is expected to own the application built on top of it.

The third key point is that the system is built so that a command-line operator, an SDK user, or an AI coding agent can all drive the same underlying workflow.

The public repo effectively describes three developer-facing modes.

The first is CLI mode.

In CLI mode, a developer or operator uses the `zkf` binary and its command surface. The public README describes compile, prove, verify, deploy, conformance, health, and related commands. This mode matters because it makes the system usable without writing Rust against the SDK directly.

The second is SDK mode.

In SDK mode, the developer uses the public API surface and the example circuit style shown in the repository. The public SDK is intentionally narrow and interface-focused. The goal is not to reveal the private kernel. The goal is to give the developer a stable, usable surface for building their own program logic.

The third is agentic mode.

In agentic mode, the system is driven through natural-language instructions interpreted by Claude Code or Codex, which then call the CLI or other exposed surfaces to execute the workflow. This is not described as a loose future idea. It is described as the intended operating model for the system.

Now it helps to turn that into an actual story.

A developer begins not with backend selection but with a statement they want to prove.

For example, they might want to prove reserve adequacy without revealing the balance.

Or they might want to prove policy satisfaction without revealing identity.

Or they might want to prove governance compliance while keeping member-level data private.

In a conventional fragmented workflow, the developer would then have to decide how to encode the statement, how to manage witnesses, how to choose a backend, how to verify outputs, and how to tie the result to deployment.

The public ZirOS developer experience says that the system should absorb most of that burden.

In CLI or SDK mode, the developer works through the exposed program-building or proof commands.

In agentic mode, the developer can state the desired property in natural language, and the AI operator can drive the rest through ZirOS surfaces.

That means the developer experience is not only about ergonomics. It is about abstraction. ZirOS is trying to move the point of human interaction upward, from cryptographic plumbing toward application intent.

This does not mean the cryptographic details disappear from the system. It means the developer is not supposed to reconstruct the entire stack manually every time.

For a listening audience, one of the most important lines in the public repo is the ownership line.

Your subsystem code belongs to you.

Your contracts belong to you.

Your domain logic belongs to you.

Your product belongs to you.

The ZirOS engine beneath it stays private.

That is the developer experience in organizational terms. The system is not asking the developer to become the proving-engine maintainer. It is asking the developer to build the application while ZirOS provides the underlying operating layer.

## 11. What agentic operation actually means here

The phrase agentic operation can drift into vagueness if it is not grounded. The public ZirOS material grounds it in a fairly practical way.

Agentic operation means the system is designed to be driven by a language model through a combination of command surfaces, structured outputs, and repeatable operational flows.

The public repository names several examples.

An agent can select a backend.

An agent can compile a circuit.

An agent can generate a witness.

An agent can prove and verify.

An agent can export a Solidity verifier.

An agent can run conformance.

An agent can perform health checks.

An agent can scaffold an application from a template.

An agent can coordinate scheduled work such as attestations or periodic conformance runs.

The key point is that the system is not described as "AI-compatible" in a loose sense. It is described as if agent operation is a design input. That means the CLI has to be scriptable. The outputs have to be machine-readable. The errors have to be actionable. The workflow has to be decomposable into steps an agent can execute reliably.

This is also where ZirOS differs from a lot of developer tools that later add a thin AI wrapper. The public repo suggests that ZirOS is designed with the expectation that agents will be first-class operators.

That has consequences for the meaning of developer experience.

In a traditional toolchain, developer experience is mostly about what a human types and reads.

In ZirOS, developer experience includes what an agent can plan, run, inspect, and repair on behalf of the human.

This matters because zero-knowledge workflows often contain many steps that are deterministic but tedious. Backend selection, proving, verification, export, conformance, health checks, and deployment checks can all be formalized well enough that an agent can do them repeatedly. If the system exposes the right operational contract, then the developer can move up one level and describe the goal rather than each substep.

For listening purposes, the practical meaning is simple.

ZirOS is trying to let a developer tell the system what they want proved, while an AI operator handles the compile, prove, verify, and surrounding operational steps through a public and scriptable surface.

That does not mean every result is effortless. It means the system is organized around that style of work.

## 12. The prompt-to-subsystem idea

One of the strongest public ideas associated with ZirOS is the notion that a developer can give Claude Code or Codex a prompt and have the system produce a complete subsystem rather than only a single proof artifact.

This idea needs careful explanation because it can otherwise sound vague.

A subsystem, in the public ZirOS framing, is not just a circuit.

It includes the proof statement.

It includes the program or circuit surface.

It includes witness handling.

It includes proof generation and verification.

It includes export or deployment surfaces when needed.

It includes the public and private boundary.

It can include selective disclosure rules.

It can include Compact contract surfaces for Midnight.

And it can include the operational scripts or commands required to make the subsystem usable in practice.

That is a much larger promise than "the model writes a circuit."

The public repository does not expose the private internal orchestration that makes this possible. But it does repeatedly frame the developer experience in these subsystem-level terms. The system is not described as merely helping developers author one proof. It is described as helping them materialize a usable zero-knowledge application surface.

Why does that matter.

Because it is much closer to how developers think about real products.

A developer usually does not say, "I want a circuit with a certain polynomial structure." They usually say, "I want to prove this business or governance or policy fact without revealing the underlying data." They think in terms of applications, workflows, and rules.

The public ZirOS story is that the system is built to accept that higher-level expression of intent and then drive the lower-level proving machinery beneath it.

That is also why the ownership language matters so much. If the subsystem is the thing the developer cares about, then it matters that the subsystem belongs to the developer. The public repo is explicit that the engine remains private, while the app layer belongs to the builder.

For a listening audience, the key idea is this.

ZirOS is trying to turn a prompt into a subsystem, not only a prompt into a proof.

That is a more demanding goal.

It also explains why ZirOS needs to be more than a backend.

## 13. What a developer is meant to own, and what ZirOS is meant to own

This split is foundational enough that it deserves its own section.

The public ZirOS model says the developer owns the application layer.

That includes domain logic.

It includes contracts.

It includes interface design.

It includes product-specific rules.

It includes licensing for the app layer.

It includes the subsystem as a product.

ZirOS, by contrast, owns the engine beneath that.

That includes proving internals.

It includes the private GPU machinery.

It includes runtime scheduling.

It includes the private engine implementation.

It includes the lower-level system logic that the application depends on but does not reimplement.

This is an important distinction because it resolves a common ambiguity in infrastructure products.

Sometimes a tool says "you own your code," but in practice the tool also requires the user to inherit large amounts of internal complexity. ZirOS is publicly framing the split more cleanly. The app belongs to the user. The engine belongs to ZirOS. The user builds on the engine without owning the engine.

That sounds obvious until you place it next to the repository design.

Because the engine remains private, the repository has to work harder to make the boundary legible. That is why the public SDK is narrow. That is why the binary manifest is published. That is why the theorem ledger is summarized. That is why the conformance data is published. That is why the public repo keeps repeating what the boundary is.

This also clarifies what the developer experience is not supposed to be.

The developer experience is not supposed to be reverse engineering the kernel.

It is not supposed to be rebuilding the whole proof stack by hand.

It is not supposed to be carrying the burden of low-level proving infrastructure inside every subsystem repository.

The system is explicitly trying to keep those burdens below the application line.

For listening purposes, this is one of the simplest strong statements in the whole public model.

You own the application.

You do not own the operating system beneath it.

That is the intended developer relationship to ZirOS.

## 14. What the public evidence says about trust and assurance

A report about ZirOS would be incomplete if it described the system surface without describing the assurance surface.

The public evidence says several things clearly.

It says there are 169 mechanized ledger rows and 0 pending rows in the current public summary.

It says the published conformance set currently covers 24 out of 24 tests across the four publicly attested lanes.

It says binary hashes are published for the released artifacts.

It says the repository publishes coverage and mitigation position papers that distinguish between mechanized, bounded, and operational controls.

It says the public attestation package is refreshed on a recurring basis.

Each of those tells a different part of the trust story.

The theorem counts tell a listener that the project is not claiming formal verification in a vague way. It is publishing a concrete ledger summary.

The conformance counts tell the listener that at least some part of the system is being exercised publicly and repeatedly in a way that can be checked.

The binary hashes tell the listener that release integrity is part of the public contract.

The boundary papers tell the listener that the repo is willing to explain where theorem coverage ends and where operational or bounded measures begin.

That combination matters because source-private systems have to answer a predictable question: if the source is not open, what are we meant to trust.

The public ZirOS answer is not "trust us because we say so."

The answer is "trust what we publish, and evaluate us based on the evidence we are willing to maintain publicly."

That is not zero trust. It is evidence-mediated trust.

A listening report should also say what this does not prove.

It does not prove that every documented surface has full public theorem coverage.

It does not prove that every documented backend has a matching public conformance lane in this repo.

It does not eliminate the residual trust associated with a private engine.

It does not replace a full source audit.

But it does create a system where public claims can be checked against specific files rather than left as marketing copy.

That is the assurance model this repository is making available.

## 15. Why the developer experience is tied to the assurance model

In many systems, developer experience and assurance are separate conversations. One is about ease of use. The other is about correctness and trust.

In ZirOS, the public materials suggest these two are tightly connected.

Why.

Because a proof system that is easy to drive but hard to trust is not enough.

And a proof system that is extremely rigorous but impossible to operationalize is also not enough.

The developer experience therefore has to include assurance surfaces, not just friendly commands.

That is why the public repo pairs examples and SDK material with attestation data, theorem summaries, and integrity manifests.

A developer is not only meant to compile and prove. They are also meant to inspect evidence, verify the public story, and understand the boundary they are building on.

This is especially important in the agentic model.

If an AI coding agent is going to operate the system on the developer's behalf, then the system needs strong boundaries, structured outputs, and inspectable evidence. Otherwise the human cannot confidently evaluate what the agent has done.

So the listening version of this idea is:

The developer experience is not only "type less."

It is also "operate through a surface that publishes what it is doing and what it has proven."

That is a better fit for a system that wants to be used in serious environments such as governance, compliance, privacy-preserving identity, aerospace assurance, or deployed Midnight applications.

The system is not just trying to be smoother. It is trying to be smoother without dissolving the assurance boundary.

That is a more demanding design target than convenience alone.

## 16. What ZirOS is trying to make normal

Another good way to explain why ZirOS exists is to ask what it is trying to make feel normal.

It is trying to make it normal for a developer to think in terms of what they want proved, instead of first thinking in terms of proving machinery.

It is trying to make it normal for selective disclosure to be part of application design rather than an afterthought.

It is trying to make it normal for a subsystem developer to own the subsystem while depending on a private proving kernel.

It is trying to make it normal for theorem coverage, conformance data, binary integrity, and deployment artifacts to live together in one public evidence repo.

It is trying to make it normal for Claude Code or Codex to act as a first-class operator of the proof workflow.

It is trying to make it normal for a prompt to result in a complete application-facing proving subsystem rather than a loose pile of cryptographic artifacts.

It is trying to make it normal for privacy-preserving applications on Midnight to be built with explicit selective-disclosure boundaries and explicit proof infrastructure.

And it is trying to make it normal for a source-private system to explain itself in a way that is auditable enough to be reasoned about publicly.

That list is useful because it shifts the question from "what components exist" to "what workflow is being normalized."

The public ZirOS answer is that the workflow being normalized is a full proof-centered application workflow, not just an isolated proving step.

Once that is said aloud, many details in the repo line up.

The CLI exists because a system layer needs an operator surface.

The SDK exists because developers need an app-construction surface.

The proof-server contract exists because deployment environments need an integration surface.

The Midnight contracts exist because subsystem surfaces need public deployment evidence.

The theorem ledger exists because serious systems need a public formal coverage story.

The evidence package exists because release claims need verification.

The agentic framing exists because the intended operator is increasingly an AI coding agent rather than only a human with a terminal.

All of those are facets of the same normalization project.

## 17. A listening-style walk through one representative workflow

It may help to hear one workflow in sequence.

Imagine a developer wants to build a private treasury-compliance application.

They do not want to publish raw balances.

They do not want to reveal every transaction.

But they do want to prove that the treasury satisfies a reserve or policy condition.

And they may want a regulator, auditor, or governance body to see the minimal public facts necessary to confirm compliance.

In a fragmented workflow, the developer would have to do a large amount of plumbing work by hand. They would need to formalize the statement, build the proof logic, manage witnesses, choose the backend, verify the output, think through what the public surface reveals, potentially integrate with contracts, and then build or operate the deployment flow.

In the ZirOS model, the workflow starts higher up.

The developer describes the property they want.

From there, the CLI, SDK, or agentic surface drives the system through the rest of the path.

The proving engine beneath the boundary handles compilation and proof generation through its private internals.

The public-facing surfaces expose enough structure that the developer can use the result without having to reimplement the kernel.

If the target environment is Midnight, the public proof-server contract defines how the proof-serving side is expected to behave, and the existing Midnight deployment evidence shows that this is not merely theoretical.

If the developer wants to use an AI coding agent, they can operate through Claude Code or Codex, expressing the intent at the property level and allowing the agent to drive the command surface.

At the end of the process, the developer owns the subsystem they built.

They do not own the private engine beneath it.

That is the representative ZirOS workflow in spoken form.

Of course, the public repo does not reveal every internal orchestration detail of that path. But it reveals enough of the surface to make the intended workflow understandable.

## 18. What this report is not claiming

Because this report is written for listening, it is worth being very direct about its limits.

This report is not claiming that the public repo proves every internal property of the private engine.

It is not claiming that all nine documented backends have identical current public attestation depth.

It is not claiming that every document in the repo reflects a complete end-to-end theorem of the entire system.

It is not claiming that the source-private model removes all trust.

It is not claiming that Midnight attestation deployment is already complete just because five subsystem contracts are live on preprod.

It is not claiming anything beyond the public files cited in this repository.

What it is claiming is narrower.

It is claiming that the public repo gives enough evidence to explain the system's intended shape, intended purpose, intended developer experience, current public assurance surface, and current public deployment evidence.

That is enough for a meaningful system report.

It is also enough for a listening audience to understand what ZirOS is trying to be without collapsing into either blind praise or blind skepticism.

## 19. Final synthesis

ZirOS is best understood as an attempt to move zero-knowledge development one level higher.

It does not want the center of gravity to be low-level proof plumbing.

It wants the center of gravity to be developer intent, subsystem design, selective disclosure policy, deployable proof surfaces, and evidence-backed operation.

That is what the phrase zero-knowledge operating system means in public terms.

Why does ZirOS exist.

It exists because ordinary zero-knowledge development places too much burden on the developer to assemble the proof workflow by hand.

It exists because real privacy-preserving applications need more than a proof primitive. They need a system surface that ties together statements, witnesses, proofs, verification, disclosure boundaries, deployment, integrity, and operations.

It exists because Midnight-style selective-disclosure applications require the proof system and the deployment surface to stay aligned.

It exists because the project is making a deliberate source-private choice and therefore needs a public evidence repository that can carry the trust story.

And it exists because the project treats AI coding agents as first-class operators of the workflow, which changes what the command surface and developer experience need to look like.

What is the developer experience supposed to be.

It is supposed to begin with what the developer wants to prove.

It is supposed to let the developer work through a CLI, an SDK, or an AI agent rather than through raw proving internals.

It is supposed to let the developer own the subsystem while ZirOS owns the engine beneath it.

It is supposed to support proof generation, verification, export, deployment, and disclosure boundaries as one connected path instead of many disconnected tasks.

It is supposed to expose enough public evidence that developers can reason about the system they are building on, even though the core remains private.

That is the public meaning of ZirOS as of the current attestation repository.

For a listener, the shortest complete summary is this.

ZirOS is a source-private zero-knowledge operating system with a public evidence boundary. It exists to turn a fragmented proving workflow into a usable application and deployment surface. And its developer experience is built around the idea that a human or an AI agent should be able to state what must be proven, then drive a complete subsystem through one operating layer rather than assembling the proving stack from scratch.

## 20. Source guide for listeners who want to read further

If someone hears this report and wants to verify the public basis for it, the most useful reading order is:

1. [README.md](../README.md)
2. [attestation/latest.json](../attestation/latest.json)
3. [ledger/ledger-summary.json](../ledger/ledger-summary.json)
4. [proof-server/endpoint-spec.md](../proof-server/endpoint-spec.md)
5. [midnight/explorer-links.md](../midnight/explorer-links.md)
6. [midnight/attestation-contracts.md](../midnight/attestation-contracts.md)
7. [sdk/api-surface.md](../sdk/api-surface.md)
8. [position/source-code-protection.md](../position/source-code-protection.md)
9. [position/coverage-gaps-and-mitigations.md](../position/coverage-gaps-and-mitigations.md)
10. [report/ziros-system-technical-report.md](../report/ziros-system-technical-report.md)

That sequence moves from the high-level description, to the attested evidence, to the deployment surface, to the programming surface, to the publication boundary.

For a listening audience, that is the same path this report follows in spoken form.
